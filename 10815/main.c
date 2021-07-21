#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 10000

typedef struct trie {
    int isEnd, hasChild;
    struct trie* child[127];
} Trie;

Trie* MakeTrie() { return malloc(sizeof(Trie)); }

void Insert(Trie* t, const char* word) {
    int i, len = strlen(word);
    for (i = 0; i < len; i++) {
        if (!t->hasChild) t->hasChild = 1;
        if (!t->child[(int)word[i]]) t->child[(int)word[i]] = MakeTrie();
        t = t->child[(int)word[i]];
    }
    t->isEnd = 1;
}

void Print(Trie* t, char* buf, int len) {
    if (t->isEnd && len) {
        buf[len] = '\0';
        printf("%s\n", buf);
        if (!t->hasChild) return;
    }
    char ch;
    for (ch = 0; ch < 127; ch++) {
        if (!t->child[(int)ch]) continue;
        buf[len++] = ch;
        Print(t->child[(int)ch], buf, len);
        len--;
    }
}

char s[maxn], buf[maxn];

int main() {
    Trie* t = MakeTrie();

    while (scanf("%s", s) != EOF) {
        int i, j;
        i = j = 0;
        for (; s[i]; i++)
            if ('A' <= s[i] && s[i] <= 'Z')
                buf[j++] = s[i] - 'A' + 'a';
            else if ('a' <= s[i] && s[i] <= 'z')
                buf[j++] = s[i];
            else {
                buf[j] = 0;
                Insert(t, buf);
                j = 0;
            }
        buf[j] = 0;
        Insert(t, buf);
    }

    Print(t, buf, 0);

    return 0;
}
