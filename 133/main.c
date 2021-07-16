#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n && k && m) {
        int selected[n];
        memset(selected, 0, sizeof(int) * n);

        int i = -1, j = n, remain = n, last;
        while (remain) {
            last = k;
            while (last) {
                i = (i + 1) % n;
                if (!selected[i]) last--;
            }
            printf("%3d", i + 1);
            remain--;

            last = m;
            while (last) {
                j = (j - 1 + n) % n;
                if (!selected[j]) last--;
            }
            if (i != j) {
                printf("%3d", j + 1);
                remain--;
            }

            if (remain) printf(",");
            selected[i] = 1, selected[j] = 1;
        }
        printf("\n");
    }

    return 0;
}
