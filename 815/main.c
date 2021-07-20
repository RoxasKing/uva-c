#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int main() {
    int m, n, kase = 1;
    while (scanf("%d%d", &m, &n) == 2 && m && n) {
        int len = m * n;
        int a[len], i, cubic;
        for (i = 0; i < len; i++) scanf("%d", &a[i]);
        scanf("%d", &cubic);

        qsort(a, len, sizeof(int), cmp);
        int pSum[len + 1];
        pSum[0] = 0;
        for (i = 0; i < len; i++) pSum[i + 1] = pSum[i] + a[i];

        double lvl = a[0], pct = 00.00;
        for (i = 0; i < len; i++)
            if ((a[i] * (i + 1) - pSum[i + 1]) * 100 >= cubic) break;
        if (i == len) {
            lvl = (double)(cubic + pSum[len] * 100) / (double)len / 100.00;
            pct = 100.000;
        } else if (i) {
            lvl = (double)(cubic + pSum[i] * 100) / (double)i / 100.000;
            pct = 100.000 * (double)i / (double)len;
        }

        printf("Region %d\n", kase++);
        printf("Water level is %.2lf meters.\n", lvl);
        printf("%.2lf percent of the region is under water.\n\n", pct);
    }

    return 0;
}
