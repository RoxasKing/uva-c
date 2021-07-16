#include <stdio.h>
#include <stdlib.h>
#define maxn 8

int dict[maxn][1 << maxn];

int main() {
    while (1) {
        int len, idx, ch;
        while ((ch = getchar()) == '\n' || ch == '\r')
            ;
        if (ch == EOF) break;
        dict[1][0] = ch;
        for (len = 2; len < maxn; len++) {
            for (idx = 0; idx < (1 << len) - 1; idx++) {
                if ((ch = getchar()) == '\r' || ch == '\n') goto NEXT;
                dict[len][idx] = ch;
            }
        }

    NEXT:
        while (1) {
            int a, b, c;
            while ((a = getchar()) == '\n' || a == '\r')
                ;
            while ((b = getchar()) == '\n' || b == '\r')
                ;
            while ((c = getchar()) == '\n' || c == '\r')
                ;
            if (a == '0' && b == '0' && c == '0') break;

            a -= '0', b -= '0', c -= '0';
            int len = (a << 2) + (b << 1) + c;
            while (1) {
                int i, ch, idx = 0;
                for (i = 0; i < len; i++) {
                    while ((ch = getchar()) == '\n' || ch == '\t')
                        ;
                    idx = (idx << 1) + (ch - '0');
                }
                if (idx != (1 << len) - 1)
                    putchar(dict[len][idx]);
                else
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}
