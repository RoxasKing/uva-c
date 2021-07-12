#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define m 50
#define n 1000

char ss[m][n];

char arr[] = {'A', 'C', 'G', 'T'};

int main() {
    int t;
    scanf("%d", &t);

    int r, c, i, j, k;
    char ch;
    while (t--) {
        scanf("%d%d", &r, &c);
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++) {
                while ((ch = getchar()) == '\n')
                    ;
                ss[i][j] = ch;
            }

        int sum = 0;
        for (j = 0; j < c; j++) {
            char out;
            int min = 1e9;
            for (k = 0; k < 4; k++) {
                int cur = 0;
                for (i = 0; i < r; i++)
                    if (ss[i][j] != arr[k]) cur++;
                if (cur < min) out = arr[k], min = cur;
            }
            sum += min;
            printf("%c", out);
        }
        printf("\n%d\n", sum);
    }

    return 0;
}
