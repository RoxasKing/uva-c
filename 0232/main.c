#include <stdio.h>
#include <stdlib.h>
#define n 15

char puzzle[n][n];
int grid[n][n];

int main() {
    int r, c, i, j, k, no = 0, idx, flg;
    char ch;
    for (;;) {
        scanf("%d", &r);
        if (r == 0) break;
        scanf("%d", &c);

        idx = 0, flg = 0;
        getchar();

        if (no > 0) printf("\n");
        printf("puzzle #%d:", ++no);

        printf("\nAcross");
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                while ((ch = getchar()) == '\n')
                    ;
                puzzle[i][j] = ch;
                grid[i][j] = -1;
                if (ch == '*') {
                    flg = 0;
                    continue;
                }
                if (i == 0 || j == 0 || puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*') grid[i][j] = ++idx;
                if (!flg) printf("\n%3d.", idx);
                printf("%c", puzzle[i][j]);
                flg = 1;
            }
            flg = 0;
        }

        printf("\nDown");
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j] == -1) continue;
                printf("\n%3d.", grid[i][j]);
                for (k = i; k < r && puzzle[k][j] != '*'; k++) {
                    printf("%c", puzzle[k][j]);
                    grid[k][j] = -1;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
