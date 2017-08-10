#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL bigMod(ULL x, ULL y, ULL n);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t;
    ULL x, y, n, z;

    while (scanf("%d", &test)) {
        if (!test) {
            break;
        }

        for (t = 1; t <= test; t++) {
            scanf("%llu%llu%llu", &x, &y, &n);
            z = bigMod(x, y, n);

            printf("%llu\n", z);
        }
    }

    return 0;
}

ULL bigMod(ULL x, ULL y, ULL n)
{
    ULL result;

    if (n == 1) {
        return 0;
    }
    else if (y == 0) {
        return 1;
    }
    else if (y % 2 == 0) {
        result = bigMod(x, y / 2, n);
        return ((result % n) * (result % n)) % n;
    }
    else {
        return ((x % n) * (bigMod(x, y - 1, n) % n)) % n;
    }
}

