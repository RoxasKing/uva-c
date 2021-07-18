#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100005

int t[maxn][2], ptr, ip, mask;

void insert(int x) {
    int node = 0, i, idx;
    for (i = 31; i >= 0; i--) {
        idx = (x >> i) & 1;
        if (!t[node][idx]) t[node][idx] = ++ptr;
        node = t[node][idx];
    }
}

void search() {
    int node = 0, i;
    for (i = 31; i >= 0; i--) {
        if (t[node][0] && t[node][1]) return;
        if (t[node][0]) {
            node = t[node][0];
        } else {
            node = t[node][1];
            ip |= 1 << i;
        }
        mask |= 1 << i;
    }
}

void print_ip(int x) {
    int num = 0, i;
    for (i = 31; i >= 0; i--) {
        num += ((x >> i) & 1) << (i % 8);
        if (i % 8 == 0) {
            printf("%d", num);
            if (i) printf(".");
            num = 0;
        }
    }
    printf("\n");
}

int main() {
    int m, a, b, c, d;
    while (scanf("%d", &m) == 1 && m) {
        memset(t, 0, sizeof(t));
        ip = mask = ptr = 0;
        while (m--) {
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            int x = (a << 24) + (b << 16) + (c << 8) + d;
            insert(x);
        }
        search();
        print_ip(ip);
        print_ip(mask);
    }

    return 0;
}
