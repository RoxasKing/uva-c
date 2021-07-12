#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define maxn 110

char s1[maxn];
char s2[maxn];

int main() {
    while (scanf("%s%s", s1, s2) == 2) {
        int len1 = strlen(s1), len2 = strlen(s2), i, j;
        int out = len1 + len2;
        for (i = 0; i < len1; i++) {
            int ok = 1;
            for (j = 0; j < len2 && i + j < len1; j++) {
                if ((s1[i + j] - '0') + (s2[j] - '0') > 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                out = Min(out, Max(len1, i + len2));
                break;
            }
        }
        for (i = 0; i < len2; i++) {
            int ok = 1;
            for (j = 0; j < len1 && i + j < len2; j++) {
                if ((s2[i + j] - '0') + (s1[j] - '0') > 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                out = Min(out, Max(len2, i + len1));
                break;
            }
        }

        printf("%d\n", out);
    }

    return 0;
}
