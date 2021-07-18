#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define debug 0

int main() {
    char kv[256][100], words[105][100], morses[105][100], morse[100];
    int len = 0, long_pre = 0, ch, i, j;
    memset(kv, 0, sizeof(kv));

    while (1) {
        while ((ch = getchar()) == '\n' || ch == '\t' || ch == ' ')
            ;
        if (ch == '*') break;
        scanf("%s", kv[ch]);
        if (debug) printf("%c %s\n", ch, kv[ch]);
    }

    while (1) {
        scanf("%s", words[len]);
        if (strcmp(words[len], "*") == 0) break;
        int size = 0;
        for (i = 0; i < strlen(words[len]); i++) {
            ch = words[len][i];
            for (j = 0; j < strlen(kv[ch]); j++) morses[len][size + j] = kv[ch][j];
            size += strlen(kv[ch]);
        }
        morses[len][size] = '\0';
        if (strcmp(morses[long_pre], morses[len]) > 0) long_pre = len;
        if (debug) printf("%s %s\n", words[len], morses[len]);
        len++;
    }

    while (1) {
        scanf("%s", morse);
        if (strcmp(morse, "*") == 0) break;
        int lena = strlen(morse);

        int idx1 = -1, cnt = 0, idx2 = -1, diff = 1e9;
        for (i = 0; i < len; i++) {
            int lenb = strlen(morses[i]);
            for (j = 0; j < lena && j < lenb && morse[j] == morses[i][j]; j++)
                ;

            if (j == lena && j == lenb) {
                if (idx1 == -1) idx1 = i;
                cnt++;
                continue;
            }

            if ((j == lena || j == lenb) && abs(lena - lenb) < diff) {
                diff = abs(lena - lenb);
                idx2 = i;
            }
        }

        if (idx1 != -1) {
            printf("%s", words[idx1]);
            if (cnt > 1) printf("!");
        } else if (idx2 != -1) {
            printf("%s?", words[idx2]);
        } else {
            printf("%s?", words[long_pre]);
        }
        printf("\n");
    }

    return 0;
}
