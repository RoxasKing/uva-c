#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 30

int table[maxn][maxn], len[maxn];
int n, i, j;

void find_block(int a, int* p, int* h) {
    for (*p = 0; *p < n; (*p)++)
        for (*h = 0; *h < len[*p]; (*h)++)
            if (table[*p][*h] == a) return;
}

void clear_above(int p, int h) {
    for (i = h + 1; i < len[p]; i++) {
        int b = table[p][i];
        table[b][len[b]++] = b;
    }
    len[p] = h + 1;
}

void pile_onto(int p, int h, int p2) {
    for (i = h; i < len[p]; i++) table[p2][len[p2]++] = table[p][i];
    len[p] = h;
}

void print() {
    for (i = 0; i < n; i++) {
        printf("%d:", i);
        for (j = 0; j < len[i]; j++) printf(" %d", table[i][j]);
        printf("\n");
    }
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) table[i][len[i]++] = i;

    char op1[5], op2[5];
    int a, b;
    while (scanf("%s%d%s%d", op1, &a, op2, &b) == 4 && strcmp(op1, "quit") != 0) {
        int pa, ha, pb, hb;
        find_block(a, &pa, &ha);
        find_block(b, &pb, &hb);
        if (pa == pb) continue;
        if (strcmp(op1, "move") == 0) clear_above(pa, ha);
        if (strcmp(op2, "onto") == 0) clear_above(pb, hb);
        pile_onto(pa, ha, pb);
    }

    print();
    return 0;
}
