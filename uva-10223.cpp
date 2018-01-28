#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL binomialCoeff(ULL n, ULL r);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<ULL>CATALAN;
    vector<ULL>::iterator p;
    ULL n, number;

    for (n = 1; ; n++) {
        number = binomialCoeff(2 * n, n);
        number /= (n + 1);

        if (number > 4294967295) {
            break;
        }
        CATALAN.push_back(number);
    }

    /*
    for (n = 0; n < CATALAN.size(); n++) {
        printf("%llu\n", CATALAN[n]);
    }
    */

    while (scanf("%llu", &n) != EOF) {
        p = upper_bound(CATALAN.begin(), CATALAN.end(), n);
        printf("%d\n", p - CATALAN.begin());
    }

    return 0;
}

ULL binomialCoeff(ULL n, ULL r)
{
    ULL i, res = 1;

    /// Because, C(n, r) = C(n, n - r)
    if (r > n - r) {
        r = n - r;
    }

    for (i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
