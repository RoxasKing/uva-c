#include <stdio.h>
#include <stdlib.h>

char buf[101];

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
    while (scanf("%s", buf) == 1) {
        int i, a[26], b[26];
        for (i = 0; i < 26; i++) a[i] = 0, b[i] = 0;
        for (i = 0; buf[i]; i++) a[buf[i] - 'A']++;
        scanf("%s", buf);
        for (i = 0; buf[i]; i++) b[buf[i] - 'A']++;

        qsort(a, 26, sizeof(int), cmp);
        qsort(b, 26, sizeof(int), cmp);

        int ok = 1;
        for (i = 0; i < 26 && ok; i++) {
            if (a[i] != b[i]) {
                ok = 0;
                break;
            }
        }

        ok ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}
