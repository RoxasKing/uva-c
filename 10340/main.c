#include <stdio.h>
#include <string.h>
#define maxn 100000

char a[maxn];
char b[maxn];

int main() {
    while (scanf("%s %s", a, b) == 2) {
        int lena = strlen(a), lenb = strlen(b);
        int i = 0, j = 0;
        while (i < lena && j < lenb) {
            if (a[i] == b[j]) i++;
            j++;
        }
        i == lena ? printf("Yes\n") : printf("No\n");
    }

    return 0;
}
