#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double round(double x);
float roundf(float x);
long double roundl(long double x);

const double esp = 1e-6;

char buf[256];

int main() {
    double lg2 = log10(2), a, v;
    int b, m;

    while (scanf("%s", buf) == 1 && strcmp(buf, "0e0")) {
        *strchr(buf, 'e') = ' ';
        sscanf(buf, "%lf%d", &a, &b);
        v = log10(a) + b;
        for (m = 1; m <= 10; m++) {
            int mhe = round(log10((v + m * lg2 - log10(pow(2, m) - 1)) / lg2 + 1) / lg2);
            if (fabs(((1 << mhe) - 1) * lg2 + log10(pow(2, m) - 1) - m * lg2 - v) <= esp) {
                printf("%d %d\n", m - 1, mhe);
                break;
            }
        }
    }

    return 0;
}
