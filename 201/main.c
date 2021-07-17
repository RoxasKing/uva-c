#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 9

int h[maxn + 1][maxn + 1][maxn + 1];
int v[maxn + 1][maxn + 1][maxn + 1];

int valid(int x, int y, int len, int n) {
    if (x + len > n || y + len > n) return 0;
    int i, j;
    for (i = y, j = x; i < y + len && j < x + len; i++, j++) {
        if (!h[x][i][i + 1] || !h[x + len][i][i + 1]) return 0;
        if (!v[y][j][j + 1] || !v[y + len][j][j + 1]) return 0;
    }

    return 1;
}

int main() {
    int n, m, no = 1;
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        int i, j, k;
        char t;
        for (i = 0; i <= maxn; i++) {
            for (j = 0; j <= maxn; j++) {
                h[i][j][j + 1] = 0;
                v[i][j][j + 1] = 0;
            }
        }

        while (m--) {
            while ((t = getchar()) == '\n' || t == '\t' || t == ' ')
                ;
            scanf("%d%d", &i, &j);
            if (t == 'H') h[i][j][j + 1] = 1;
            if (t == 'V') v[i][j][j + 1] = 1;
        }

        if (no > 1) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", no++);

        int ok = 0;
        for (k = 1; k <= n; k++) {
            int cnt = 0;
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (valid(i, j, k, n)) cnt++;
            if (cnt) ok = 1, printf("%d square (s) of size %d\n", cnt, k);
        }

        if (!ok) printf("No completed squares can be found.\n");
    }

    return 0;
}
