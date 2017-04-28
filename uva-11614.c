#include <stdio.h>
#include <math.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test;
    double n, rows;

    scanf("%d", &test);
    while (test--) {
        scanf("%lf", &n);

        rows = floor((-1 + sqrt(1 + 8 * n)) / 2);
        printf("%.0lf\n", rows);
    }
    return 0;
}
