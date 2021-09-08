#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define maxn 100

char s[maxn];

int main() {
    int t;
    scanf("%d", &t);

    while (t-- && scanf("%s", s)) {
        int len = strlen(s);
        int k, start, i, out = 0;
        for (k = 1; k <= len / 2 && !out; k++) {
            if (len % k) continue;
            bool ok = true;
            for (start = k; start < len && ok; start += k)
                for (i = 0; i < k && ok; i++)
                    if (s[i] != s[start + i]) ok = false;
            if (ok) out = k;
        }
        out ? printf("%d\n", out) : printf("%d\n", len);
        if (t) printf("\n");
    }
    return 0;
}
