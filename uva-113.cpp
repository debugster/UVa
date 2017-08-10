#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    double n, p, k;

    while (scanf("%lf", &n) != EOF) {
        scanf("%lf", &p);
        k = pow(p, (1.0 / n));
        printf("%.0lf\n", k);
    }
    return 0;
}
