#include <stdio.h>
#include <stdlib.h>
#define n 5

char grid[n][n];

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int i, r, c;
    for (i = 1;; i++) {
        char ch;
        int x = -100, y = -100;
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                while ((ch = getchar()) == '\n')
                    ;
                if (ch == EOF) return 0;
                grid[r][c] = ch;
                if (ch == ' ') x = r, y = c;
            }
            getchar();
        }

        if (i > 1) printf("\n");
        printf("Puzzle #%d:\n", i);

        int flg = 1;
        while ((ch = getchar()) != '0') {
            if (ch == 'A') {
                if (x <= 0) {
                    flg = 0;
                    break;
                }
                swap(&grid[x][y], &grid[x - 1][y]);
                x--;
            } else if (ch == 'B') {
                if (x >= 4) {
                    flg = 0;
                    break;
                }
                swap(&grid[x][y], &grid[x + 1][y]);
                x++;
            } else if (ch == 'L') {
                if (y <= 0) {
                    flg = 0;
                    break;
                }
                swap(&grid[x][y], &grid[x][y - 1]);
                y--;
            } else if (ch == 'R') {
                if (y >= 4) {
                    flg = 0;
                    break;
                }
                swap(&grid[x][y], &grid[x][y + 1]);
                y++;
            } else if (ch != '\n') {
                flg = 0;
                break;
            }
        }

        while (ch != '0') ch = getchar();

        if (flg) {
            for (r = 0; r < 5; r++) {
                for (c = 0; c < 5; c++) {
                    if (c) printf(" ");
                    printf("%c", grid[r][c]);
                }
                printf("\n");
            }
        } else
            printf("This puzzle has no final configuration.\n");
    }

    return 0;
}
