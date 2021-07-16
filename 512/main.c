#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int ini[maxn][maxn];     /* idx's initial position */
int cur[maxn][maxn];     /* idx's current position */
int pos[maxn * maxn][2]; /* get current position by idx */

void init(int r, int c) {
    int i, j, idx = 1;
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++) {
            ini[i][j] = idx;
            cur[i][j] = idx;
            pos[idx][0] = i;
            pos[idx][1] = j;
            idx++;
        }
}

/* void printState(int r, int c) {
    int i, j;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) printf("%3d ", cur[i][j]);
        printf("\n");
    }
} */

int main() {
    int r, c, no = 1;
    while (scanf("%d%d", &r, &c) == 2 && r && c) {
        init(r, c);
        /* printState(r, c); */

        int n;
        scanf("%d", &n);
        while (n--) {
            char op[3];
            scanf("%s", op);

            if (strcmp(op, "EX") == 0) {
                int r1, c1, r2, c2;
                scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                int i = cur[r1][c1], j = cur[r2][c2];
                if (i && j) {
                    cur[r2][c2] = i, pos[i][0] = r2, pos[i][1] = c2;
                    cur[r1][c1] = j, pos[j][0] = r1, pos[j][1] = c1;
                } else if (i) {
                    cur[r2][c2] = i, pos[i][0] = r2, pos[i][1] = c2;
                    cur[r1][c1] = 0, pos[j][0] = 0, pos[j][1] = 0;
                } else if (j) {
                    cur[r2][c2] = 0, pos[i][0] = 0, pos[i][1] = 0;
                    cur[r1][c1] = j, pos[j][0] = r1, pos[j][1] = c1;
                }
                /* printState(r, c); */

            } else if (strcmp(op, "DC") == 0) {
                int del;
                scanf("%d", &del);
                int k, arr[del];
                for (k = 0; k < del; k++) scanf("%d", &arr[k]);
                qsort(arr, del, sizeof(int), cmp);
                for (k = del - 1; k >= 0; k--) {
                    int col = arr[k];
                    int i, j;
                    for (i = 1; i <= r; i++) {
                        int idx = cur[i][col];
                        if (idx) pos[idx][0] = 0, pos[idx][1] = 0;
                    }
                    for (i = 1; i <= r; i++) {
                        for (j = col; j < c; j++) {
                            int idx = cur[i][j + 1];
                            if (idx)
                                pos[idx][1]--, cur[i][j] = idx;
                            else
                                cur[i][j] = 0;
                        }
                        cur[i][c] = 0;
                    }
                    c--;
                }
                /* printState(r, c); */

            } else if (strcmp(op, "DR") == 0) {
                int del;
                scanf("%d", &del);
                int k, arr[del];
                for (k = 0; k < del; k++) scanf("%d", &arr[k]);
                qsort(arr, del, sizeof(int), cmp);
                for (k = del - 1; k >= 0; k--) {
                    int row = arr[k];
                    int i, j;
                    for (j = 1; j <= c; j++) {
                        int idx = cur[row][j];
                        if (idx) pos[idx][0] = 0, pos[idx][1] = 0;
                    }
                    for (j = 1; j <= c; j++) {
                        for (i = row; i < r; i++) {
                            int idx = cur[i + 1][j];
                            if (idx)
                                pos[idx][0]--, cur[i][j] = idx;
                            else
                                cur[i][j] = 0;
                        }
                        cur[r][j] = 0;
                    }
                    r--;
                }
                /* printState(r, c); */

            } else if (strcmp(op, "IC") == 0) {
                int ins;
                scanf("%d", &ins);
                int k, arr[ins];
                for (k = 0; k < ins; k++) scanf("%d", &arr[k]);
                qsort(arr, ins, sizeof(int), cmp);
                for (k = ins - 1; k >= 0; k--) {
                    int col = arr[k];
                    int i, j;
                    for (i = 1; i <= r; i++) {
                        for (j = c; j >= col; j--) {
                            int idx = cur[i][j];
                            if (idx)
                                pos[idx][1]++, cur[i][j + 1] = idx;
                            else
                                cur[i][j + 1] = idx;
                        }
                        cur[i][col] = 0;
                    }
                    c++;
                }
                /* printState(r, c); */

            } else if (strcmp(op, "IR") == 0) {
                int ins;
                scanf("%d", &ins);
                int k, arr[ins];
                for (k = 0; k < ins; k++) scanf("%d", &arr[k]);
                qsort(arr, ins, sizeof(int), cmp);
                for (k = ins - 1; k >= 0; k--) {
                    int row = arr[k];
                    int i, j;
                    for (j = 1; j <= c; j++) {
                        for (i = r; i >= row; i--) {
                            int idx = cur[i][j];
                            if (idx)
                                pos[idx][0]++, cur[i + 1][j] = idx;
                            else
                                cur[i + 1][j] = 0;
                        }
                        cur[row][j] = 0;
                    }
                    r++;
                }
                /* printState(r, c); */
            }
        }

        if (no > 1) printf("\n");
        printf("Spreadsheet #%d\n", no++);

        scanf("%d", &n);
        while (n--) {
            int row, col;
            scanf("%d%d", &row, &col);
            int idx = ini[row][col];
            int x = pos[idx][0], y = pos[idx][1];
            if (!x && !y) {
                printf("Cell data in (%d,%d) GONE\n", row, col);
                continue;
            }
            printf("Cell data in (%d,%d) moved to (%d,%d)\n", row, col, x, y);
        }
    }

    return 0;
}
