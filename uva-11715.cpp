#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int op, test = 1;
    double x, y, z, m, n;

    while (scanf("%d", &op) && op != 0) {
        scanf("%lf%lf%lf", &x, &y, &z);

        printf("Case %d: ", test++);

        switch (op) {
            case 1:
                /// a = (v - u) / t
                n = (y - x) / z;
                /// s = (u * t) + (0.5 * a * t * t)
                m = (x * z) + (0.5 * n * z * z);
                break;

            case 2:
                /// t = (v - u) / a
                n = (y - x) / z;
                /// s = (u * t) + (0.5 * a * t * t)
                m = (x * n) + (0.5 * z * n * n);
                break;

            case 3:
                /// v = sqrt((u * u) + (2 * a * s))
                m = sqrt((x * x) + (2 * y * z));
                /// t = (v - u) / a
                n = (m - x) / y;
                break;

            case 4:
                /// u = sqrt((v * v) - (2 * a * s))
                m = sqrt((x * x) - (2 * y * z));
                /// t = (v - u) / a
                n = (x - m) / y;
                break;
        }
        printf("%.3lf %.3lf\n", m, n);
    }
    return 0;
}
