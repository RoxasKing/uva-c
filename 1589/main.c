#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define r 10
#define c 9

char occupy[r + 1][c + 1];

int ok(int x, int y) {
    if (x < 1 || 3 < x || y < 4 || 6 < y) return 1;
    int i, j, piece = 0;
    for (i = x + 1; i <= r; i++) {
        if (occupy[i][y] == 0) continue;
        if (!piece && (occupy[i][y] == 'R' || occupy[i][y] == 'G')) return 1;
        if (piece == 1 && occupy[i][y] == 'C') return 1;
        piece++;
    }
    piece = 0;
    for (i = x - 1; i >= 1; i--) {
        if (occupy[i][y] == 0) continue;
        if (!piece && (occupy[i][y] == 'R')) return 1;
        if (piece == 1 && occupy[i][y] == 'C') return 1;
        piece++;
    }
    piece = 0;
    for (j = y + 1; j <= c; j++) {
        if (occupy[x][j] == 0) continue;
        if (!piece && occupy[x][j] == 'R') return 1;
        if (piece == 1 && occupy[x][j] == 'C') return 1;
        piece++;
    }
    piece = 0;
    for (j = y - 1; j >= 1; j--) {
        if (occupy[x][j] == 0) continue;
        if (!piece && occupy[x][j] == 'R') return 1;
        if (piece == 1 && occupy[x][j] == 'C') return 1;
        piece++;
    }
    if (x - 1 >= 1 && !occupy[x - 1][y - 1] && occupy[x - 1][y - 2] == 'H') return 1;
    if (x - 2 >= 1 && !occupy[x - 1][y - 1] && occupy[x - 2][y - 1] == 'H') return 1;
    if (x - 1 >= 1 && !occupy[x - 1][y + 1] && occupy[x - 1][y + 2] == 'H') return 1;
    if (x - 2 >= 1 && !occupy[x - 1][y + 1] && occupy[x - 2][y + 1] == 'H') return 1;
    if (!occupy[x + 1][y + 1] && occupy[x + 1][y + 2] == 'H') return 1;
    if (!occupy[x + 1][y + 1] && occupy[x + 2][y + 1] == 'H') return 1;
    if (!occupy[x + 1][y - 1] && occupy[x + 2][y - 1] == 'H') return 1;
    if (!occupy[x + 1][y - 1] && occupy[x + 1][y - 2] == 'H') return 1;

    return 0;
}

int main() {
    int i, n, x0, y0, x, y;
    char p;
    while (scanf("%d%d%d", &n, &x0, &y0) == 3 && n && x0 && y0) {
        for (i = 0; i < r + 1; i++) memset(occupy[i], 0, sizeof(char) * (c + 1));

        while (n--) {
            while ((p = getchar()) == '\n' || p == '\r' || p == ' ')
                ;
            scanf("%d%d", &x, &y);
            occupy[x][y] = p;
        }

        int fly = 0;
        for (i = x0; i <= r; i++)
            if (occupy[i][y0] != 0) {
                fly = occupy[i][y0] == 'G';
                break;
            }

        int checkmate = !fly && ok(x0 - 1, y0) && ok(x0 + 1, y0) && ok(x0, y0 - 1) && ok(x0, y0 + 1);

        checkmate ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}
