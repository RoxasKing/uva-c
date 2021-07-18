#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateX(char* cube) {
    char t = cube[0];
    cube[0] = cube[3];
    cube[3] = cube[5];
    cube[5] = cube[2];
    cube[2] = t;
}
void rotateY(char* cube) {
    char t = cube[0];
    cube[0] = cube[4];
    cube[4] = cube[5];
    cube[5] = cube[1];
    cube[1] = t;
}
void rotateZ(char* cube) {
    char t = cube[1];
    cube[1] = cube[3];
    cube[3] = cube[4];
    cube[4] = cube[2];
    cube[2] = t;
}

int main() {
    char buf[13];
    while (scanf("%s", buf) == 1) {
        char c1[7], c2[7];
        int i, j, ok = 0;
        for (i = 0; i < 6; i++) {
            c1[i] = buf[i];
            c2[i] = buf[i + 6];
        }
        c1[6] = '\0';
        c2[6] = '\0';

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 4; j++) {
                if (strcmp(c1, c2) == 0) {
                    ok = 1;
                    break;
                }
                rotateX(c2);
            }
            if (ok) break;
            if (i <= 3) rotateZ(c2);
            if (i == 3) rotateY(c2);
            if (i == 4) rotateY(c2), rotateY(c2);
        }

        ok ? printf("TRUE\n") : printf("FALSE\n");
    }

    return 0;
}
