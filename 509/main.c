#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxd 7   /* the number of disks limit */
#define maxb 101 /* each disk's blocks limit */
#define maxs 65  /* each block's bits limit */

int d, s, b;
char typ;
int data[maxd][maxb][maxs];
int xors[maxb][maxs]; /* xor sum of each bit */
int badb[maxb][maxs]; /* count the number of unavaliable bits */

void read();
int recover();
void print_hex();

int main() {
    int kase = 0;
    while (scanf("%d%d%d", &d, &s, &b) == 3 && d && s && b) {
        while ((typ = getchar()) == '\n' || typ == '\t' || typ == ' ')
            ;
        memset(xors, 0, sizeof(xors));
        memset(badb, 0, sizeof(badb));
        read();
        if (!recover())
            printf("Disk set %d is invalid.\n", ++kase);
        else {
            printf("Disk set %d is valid, contents are: ", ++kase), print_hex();
        }
    }

    return 0;
}

void read() {
    int i, j, k, ch;
    for (i = 0; i < d; i++) {
        for (j = 0; j < b; j++) {
            for (k = 0; k < s; k++) {
                while ((ch = getchar()) == '\n' || ch == '\t' || ch == ' ')
                    ;
                if (ch == 'x') {
                    data[i][j][k] = 2; /* unavaliable bit */
                    badb[j][k]++;
                } else {
                    data[i][j][k] = ch - '0';
                    xors[j][k] ^= data[i][j][k]; /* calculate the xor of each bit */
                }
            }
        }
    }
}

int recover() {
    int i, j, k;
    for (j = 0; j < b; j++) {     /* block */
        for (k = 0; k < s; k++) { /* bit */
            if (badb[j][k] > 1) return 0;
            if (badb[j][k] == 0 && xors[j][k] != (typ == 'E' ? 0 : 1)) return 0;
            for (i = 0; i < d; i++) { /* disk */
                if (data[i][j][k] == 2) data[i][j][k] = xors[j][k] ^ (typ == 'E' ? 0 : 1);
            }
        }
    }
    return 1;
}

char dict[] = "0123456789ABCDEF";

void print_hex() {
    int i, j, k, cnt = 0, idx = 0;
    for (j = 0; j < b; j++) {         /* block */
        for (i = 0; i < d; i++) {     /* dist */
            if (j % d == i) continue; /* check block, skip */
            for (k = 0; k < s; k++) { /* bit */
                idx = (idx << 1) + data[i][j][k];
                if (++cnt == 4) printf("%c", dict[idx]), cnt = idx = 0;
            }
        }
    }
    if (cnt) printf("%c", dict[idx <<= (4 - cnt)]);
    printf("\n");
}
