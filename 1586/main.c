#include <stdio.h>
#include <string.h>
#define maxn 100

char s[maxn];

int main() {
    int t;
    scanf("%d\n", &t);

    while (t--) {
        scanf("%s\n", s);
        char pre = ' ';
        int i, cnt = 0;
        double sum = 0;
        for (i = 0; i < strlen(s); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
                continue;
            }
            if (cnt == 0) cnt = 1;
            if (pre == 'C') sum += 12.01 * cnt;
            if (pre == 'H') sum += 1.008 * cnt;
            if (pre == 'O') sum += 16.00 * cnt;
            if (pre == 'N') sum += 14.01 * cnt;
            pre = s[i];
            cnt = 0;
        }
        if (cnt == 0) cnt = 1;
        if (pre == 'C') sum += 12.01 * cnt;
        if (pre == 'H') sum += 1.008 * cnt;
        if (pre == 'O') sum += 16.00 * cnt;
        if (pre == 'N') sum += 14.01 * cnt;
        printf("%.03lf\n", sum);
    }

    return 0;
}
