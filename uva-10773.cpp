#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t;
    double d, u, v, timeDiff;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%lf%lf%lf", &d, &v, &u);

        printf("Case %d: ", t);

        if (v < u) {
            timeDiff = abs( (d / sqrt( (u * u) - (v * v) ) ) - (d / u) );
            if (timeDiff == 0.000000) {
                printf("can\'t determine\n");
            }
            else {
                printf("%.3lf\n", timeDiff);
            }
        }
        else {
            printf("can\'t determine\n");
        }
    }

    return 0;
}

