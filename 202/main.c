#include <stdio.h>
#define hashn 3001
#define bufn 10000

int hash[hashn];
int buf[bufn];

int main() {
    int a, b, i;
    while (scanf("%d%d", &a, &b) == 2) {
        for (i = 0; i < hashn; i++) hash[i] = -1;

        int res = a / b;
        int remain = a % b;
        int l = -1, r = 0;
        while (remain) {
            if (hash[remain] != -1) {
                l = hash[remain];
                break;
            }
            hash[remain] = r;
            remain *= 10;
            buf[r++] = remain / b;
            remain %= b;
        }

        printf("%d/%d = %d.", a, b, res);
        if (l != -1) {
            for (i = 0; i < l; i++) printf("%d", buf[i]);
            printf("(");
            for (i = l; i < r && i < 50; i++) printf("%d", buf[i]);
            if (r > 50) printf("...");
            printf(")\n");
        } else {
            l = r - 1;
            for (i = 0; i < r; i++) printf("%d", buf[i]);
            printf("(0)\n");
        }

        printf("   %d = number of digits in repeating cycle\n\n", r - l);
    }

    return 0;
}
