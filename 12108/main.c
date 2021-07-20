#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 100000

int main() {
    int n, i, a, b, c, sts[10][3], kase = 1;
    while (scanf("%d", &n) == 1 && n) {
        int sleep = 0;
        for (i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            sts[i][0] = a, sts[i][1] = b, sts[i][2] = c;
            sleep += c > a ? 1 : 0;
        }

        int finish[n];
        memset(finish, 0, sizeof(finish));

        int t = 1;
        while (sleep && t < LIMIT) {
            t++;
            int can_sleep = sleep > n - sleep;
            for (i = 0; i < n; i++) {
                if (finish[i]) continue;
                if (sts[i][2] == sts[i][0]) {
                    if (can_sleep) {
                        sts[i][2]++;
                        sleep++;
                    } else {
                        finish[i] = 1;
                    }
                } else {
                    sts[i][2]++;
                    if (sts[i][2] > sts[i][0] + sts[i][1]) sts[i][2] = 1, sleep--;
                }
            }
        }

        int out = sleep ? -1 : t;

        printf("Case %d: %d\n", kase++, out);
    }

    return 0;
}
