#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long d;
    double n;
    int test = 1;

    while (scanf("%llu", &d)) {
        if (d == 0) {
            break;
        }

        /// Let n be the number of sides of polygon
        /// and d be the number of diagonals
        /// Relation between them :
        /// d = (n * (n - 3)) / 2
        /// n = (3 + sqrt(9 + 8d)) / 2
        n = ceil((3.0 + sqrt(9 + 8 * d)) / 2.0);
        printf("Case %d: %.0lf\n", test++, n);
    }
    return 0;
}
