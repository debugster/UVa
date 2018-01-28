#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long n, r, res, i;

    while (scanf("%llu%llu", &n, &r)) {
        if (!n && !r) {
            break;
        }

        if (n == r) {
            printf("1\n");
            continue;
        }
        else if (r == 1) {
            printf("%llu\n", n);
            continue;
        }

        /// Because, C(n, r) = C(n, n - r)
        if (r > n - r) {
            r = n - r;
        }

        res = 1;
        for (i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }

        printf("%llu\n", res);
    }

    return 0;
}

