#include <stdio.h>
#include <string.h>
#define maxn 100

char s[maxn];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%s", s);

        int i, out = 0, cnt = 0;
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == 'O')
                cnt++;
            else
                cnt = 0;
            out += cnt;
        }

        printf("%d\n", out);
    }

    return 0;
}
