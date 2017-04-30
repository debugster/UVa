#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t;
    double c, f, d;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%lf%lf", &c, &d);

        f = (9 * c / 5) + 32;
        f += d;
        c = (f - 32) * (5 / 9.0);
        printf("Case %d: %.2lf\n", t, c);
    }
    return 0;
}
