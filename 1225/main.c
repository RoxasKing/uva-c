#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int n, cnt[10], i, base;
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < 10; i++) cnt[i] = 0;

        for (base = 1; base <= n; base *= 10) {
            int l = n / (base * 10);
            int m = n / base % 10;
            int r = n % base;
            for (i = 1; i < 10; i++) cnt[i] += l * base;
            for (i = 1; i < m; i++) cnt[i] += base;
            if (l > 0) cnt[0] += (l - 1) * base;
            if (l > 0 && m > 0) cnt[0] += base;
            cnt[m] += r + 1;
        }

        for (i = 0; i < 10; i++) {
            if (i) printf(" ");
            printf("%d", cnt[i]);
        }
        printf("\n");
    }

    return 0;
}
