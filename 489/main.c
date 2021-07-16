#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1000

char a[maxn], b[maxn];

int main() {
    int n;
    while (scanf("%d%s%s", &n, a, b) == 3 && n != -1) {
        int lena = strlen(a), lenb = strlen(b);
        int i, lack = 0, memo = 0, cnt = 0, win = 0, lose = 0;
        for (i = 0; i < lena; i++) lack |= 1 << (a[i] - 'a');
        for (i = 0; i < lenb; i++) {
            int x = 1 << (b[i] - 'a');
            if (lack & x)
                lack ^= x;
            else if (!(memo & x))
                cnt++;
            memo |= x;
            if (cnt == 7) lose = 1;
            if (!lack) win = 1;
            if (win || lose) break;
        }

        printf("Round %d\n", n);
        if (win)
            printf("You win.\n");
        else if (lose)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }

    return 0;
}
