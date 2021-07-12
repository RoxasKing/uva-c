#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a1, a2, b1, b2, c1, c2, d1, d2, e1, e2, f1, f2;

    while (scanf("%d%d", &a1, &a2) == 2) {
        if (a1 < a2) swap(&a1, &a2);
        scanf("%d%d", &b1, &b2);
        if (b1 < b2) swap(&b1, &b2);
        scanf("%d%d", &c1, &c2);
        if (c1 < c2) swap(&c1, &c2);
        scanf("%d%d", &d1, &d2);
        if (d1 < d2) swap(&d1, &d2);
        scanf("%d%d", &e1, &e2);
        if (e1 < e2) swap(&e1, &e2);
        scanf("%d%d", &f1, &f2);
        if (f1 < f2) swap(&f1, &f2);

        if ((a1 < b1) || ((a1 == b1) && (a2 < b2))) swap(&a1, &b1), swap(&a2, &b2);
        if ((a1 < c1) || ((a1 == c1) && (a2 < c2))) swap(&a1, &c1), swap(&a2, &c2);
        if ((a1 < d1) || ((a1 == d1) && (a2 < d2))) swap(&a1, &d1), swap(&a2, &d2);
        if ((a1 < e1) || ((a1 == e1) && (a2 < e2))) swap(&a1, &e1), swap(&a2, &e2);
        if ((a1 < f1) || ((a1 == f1) && (a2 < f2))) swap(&a1, &f1), swap(&a2, &f2);

        if ((b1 < c1) || ((b1 == c1) && (b2 < c2))) swap(&b1, &c1), swap(&b2, &c2);
        if ((b1 < d1) || ((b1 == d1) && (b2 < d2))) swap(&b1, &d1), swap(&b2, &d2);
        if ((b1 < e1) || ((b1 == e1) && (b2 < e2))) swap(&b1, &e1), swap(&b2, &e2);
        if ((b1 < f1) || ((b1 == f1) && (b2 < f2))) swap(&b1, &f1), swap(&b2, &f2);

        if ((c1 < d1) || ((c1 == d1) && (b2 < d2))) swap(&c1, &d1), swap(&c2, &d2);
        if ((c1 < e1) || ((c1 == e1) && (b2 < e2))) swap(&c1, &e1), swap(&c2, &e2);
        if ((c1 < f1) || ((c1 == f1) && (b2 < f2))) swap(&c1, &f1), swap(&c2, &f2);

        if ((d1 < e1) || ((d1 == e1) && (d2 < e2))) swap(&d1, &e1), swap(&d2, &e2);
        if ((d1 < f1) || ((d1 == f1) && (d2 < f2))) swap(&d1, &f1), swap(&d2, &f2);

        if ((e1 < f1) || ((e1 == f1) && (e2 < f2))) swap(&e1, &f1), swap(&e2, &f2);

        if ((a1 != b1) || (a2 != b2) || (c1 != d1) || (c2 != d2) || (e1 != f1) || (e2 != f2)) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        if ((a1 != c1) || !((a2 == e1) || (a2 == e2)) || !((c2 == e1) || (c2 == e2))) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        printf("POSSIBLE\n");
    }

    return 0;
}
