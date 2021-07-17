#include <stdio.h>
#include <stdlib.h>
#define debug 0
#define maxn 8

char board[maxn + 1][maxn + 1];

void list(char);
int valid(char, int, int);
int move(char, int, int);
void printBoard();

int main() {
    int t, no;
    scanf("%d", &t);
    for (no = 1; no <= t; no++) {
        int i, j;
        char ch;
        for (i = 1; i <= maxn; i++)
            for (j = 1; j <= maxn; j++) {
                while ((ch = getchar()) == '\n' || ch == '\t' || ch == ' ')
                    ;
                board[i][j] = ch;
            }

        if (debug) {
            printf("\n");
            printBoard();
            printf("\n");
        }

        if (no > 1) printf("\n");

        while ((ch = getchar()) == '\n' || ch == '\t' || ch == ' ')
            ;
        char turn = ch, op;
        int r, c;
        while (1) {
            while ((op = getchar()) == '\n' || op == '\t' || op == ' ')
                ;
            if (op == 'Q') break;
            if (op == 'L') list(turn);
            if (op == 'M') {
                r = getchar() - '0';
                c = getchar() - '0';
                if (!move(turn, r, c)) {
                    turn = (turn == 'B') ? 'W' : 'B';
                    move(turn, r, c);
                }
                turn = (turn == 'B') ? 'W' : 'B';
            }
        }

        printBoard();
    }

    return 0;
}

void list(char turn) {
    int i, j, cnt = 0;
    for (i = 1; i <= maxn; i++) {
        for (j = 1; j <= maxn; j++) {
            if (board[i][j] != '-') continue;
            if (valid(turn, i, j)) {
                if (cnt) printf(" ");
                printf("(%d,%d)", i, j), cnt++;
            }
        }
    }
    if (!cnt) printf("No legal move.");
    printf("\n");
}

int valid(char turn, int r, int c) {
    char rival = (turn == 'W') ? 'B' : 'W';
    int i, j;
    if (r + 1 < maxn && board[r + 1][c] == rival) { /* right */
        for (i = r + 1; i < maxn && board[i][c] == rival; i++)
            ;
        if (board[i][c] == turn) return 1;
    }
    if (r - 1 > 1 && board[r - 1][c] == rival) { /* left */
        for (i = r - 1; i > 1 && board[i][c] == rival; i--)
            ;
        if (board[i][c] == turn) return 1;
    }
    if (c + 1 < maxn && board[r][c + 1] == rival) { /* down */
        for (j = c + 1; j < maxn && board[r][j] == rival; j++)
            ;
        if (board[r][j] == turn) return 1;
    }
    if (c - 1 > 1 && board[r][c - 1] == rival) { /* up */
        for (j = c - 1; j > 1 && board[r][j] == rival; j--)
            ;
        if (board[r][j] == turn) return 1;
    }
    if (r + 1 < maxn && c + 1 < maxn && board[r + 1][c + 1] == rival) { /* right + down */
        for (i = r + 1, j = c + 1; i < maxn && j < maxn && board[i][j] == rival; i++, j++)
            ;
        if (board[i][j] == turn) return 1;
    }
    if (r - 1 > 1 && c - 1 > 1 && board[r - 1][c - 1] == rival) { /* left + up */
        for (i = r - 1, j = c - 1; i > 1 && j > 1 && board[i][j] == rival; i--, j--)
            ;
        if (board[i][j] == turn) return 1;
    }
    if (r + 1 < maxn && c - 1 > 1 && board[r + 1][c - 1] == rival) { /* right + up */
        for (i = r + 1, j = c - 1; i < maxn && j > 1 && board[i][j] == rival; i++, j--)
            ;
        if (board[i][j] == turn) return 1;
    }
    if (r - 1 > 1 && c + 1 < maxn && board[r - 1][c + 1] == rival) { /* left + down */
        for (i = r - 1, j = c + 1; i > 1 && j < maxn && board[i][j] == rival; i--, j++)
            ;
        if (board[i][j] == turn) return 1;
    }

    return 0;
}

int move(char turn, int r, int c) {
    int i, j, ok = 0;

    char rival = (turn == 'W') ? 'B' : 'W';
    if (r + 1 < maxn && board[r + 1][c] == rival) { /* right */
        for (i = r + 1; i < maxn && board[i][c] == rival; i++)
            ;
        if (board[i][c] == turn) {
            for (i = r + 1; i < maxn && board[i][c] == rival; i++) board[i][c] = turn;
            ok = 1;
        }
    }
    if (r - 1 > 1 && board[r - 1][c] == rival) { /* left */
        for (i = r - 1; i > 1 && board[i][c] == rival; i--)
            ;
        if (board[i][c] == turn) {
            for (i = r - 1; i > 1 && board[i][c] == rival; i--) board[i][c] = turn;
            ok = 1;
        }
    }
    if (c + 1 < maxn && board[r][c + 1] == rival) { /* down */
        for (j = c + 1; j < maxn && board[r][j] == rival; j++)
            ;
        if (board[r][j] == turn) {
            for (j = c + 1; j < maxn && board[r][j] == rival; j++) board[r][j] = turn;
            ok = 1;
        }
    }
    if (c - 1 > 1 && board[r][c - 1] == rival) { /* up */
        for (j = c - 1; j > 1 && board[r][j] == rival; j--)
            ;
        if (board[r][j] == turn) {
            for (j = c - 1; j > 1 && board[r][j] == rival; j--) board[r][j] = turn;
            ok = 1;
        }
    }
    if (r + 1 < maxn && c + 1 < maxn && board[r + 1][c + 1] == rival) { /* right + down */
        for (i = r + 1, j = c + 1; i < maxn && j < maxn && board[i][j] == rival; i++, j++)
            ;
        if (board[i][j] == turn) {
            for (i = r + 1, j = c + 1; i < maxn && j < maxn && board[i][j] == rival; i++, j++) board[i][j] = turn;
            ok = 1;
        }
    }
    if (r - 1 > 1 && c - 1 > 1 && board[r - 1][c - 1] == rival) { /* left + up */
        for (i = r - 1, j = c - 1; i > 1 && j > 1 && board[i][j] == rival; i--, j--)
            ;
        if (board[i][j] == turn) {
            for (i = r - 1, j = c - 1; i > 1 && j > 1 && board[i][j] == rival; i--, j--) board[i][j] = turn;
            ok = 1;
        }
    }
    if (r + 1 < maxn && c - 1 > 1 && board[r + 1][c - 1] == rival) { /* right + up */
        for (i = r + 1, j = c - 1; i < maxn && j > 1 && board[i][j] == rival; i++, j--)
            ;
        if (board[i][j] == turn) {
            for (i = r + 1, j = c - 1; i < maxn && j > 1 && board[i][j] == rival; i++, j--) board[i][j] = turn;
            ok = 1;
        }
    }
    if (r - 1 > 1 && c + 1 < maxn && board[r - 1][c + 1] == rival) { /* left + down */
        for (i = r - 1, j = c + 1; i > 1 && j < maxn && board[i][j] == rival; i--, j++)
            ;
        if (board[i][j] == turn) {
            for (i = r - 1, j = c + 1; i > 1 && j < maxn && board[i][j] == rival; i--, j++) board[i][j] = turn;
            ok = 1;
        }
    }

    if (!ok) return 0;

    board[r][c] = turn;

    int b = 0, w = 0;
    for (i = 1; i <= maxn; i++)
        for (j = 1; j <= maxn; j++) {
            if (board[i][j] == 'B') b++;
            if (board[i][j] == 'W') w++;
        }

    printf("Black - %2d White - %2d\n", b, w);

    return 1;
}

void printBoard() {
    int i, j;
    for (i = 1; i <= maxn; i++) {
        for (j = 1; j <= maxn; j++) printf("%c", board[i][j]);
        printf("\n");
    }
}
