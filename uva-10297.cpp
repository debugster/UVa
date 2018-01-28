#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    double D, V, d;

    while (scanf("%lf%lf", &D, &V)) {
        if (!D && !V) {
            break;
        }

        d = pow((D * D * D) - (6 * V / PI), (1.0/3));
        printf("%.3lf\n", d);
    }
    return 0;
}
