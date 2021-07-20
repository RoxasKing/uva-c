#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    ll n, p, q;
    while (scanf("%lld%lld%lld", &n, &p, &q) == 3) {
        ll k = (ll)1 << 62, a = 0, b = 0, i, j;
        for (i = 0; i < 32; i++)
            for (j = 0; j < 32; j++) {
                ll res = (((n - 1) * p + ((n - 1) * p << i)) >> j) + q;
                if (res >= n * q && res < k) k = res, a = i, b = j;
            }
        printf("%lld %lld %lld\n", k, a, b);
    }

    return 0;
}
