#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, x, y, r;
    double longest, shortest;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d%d", &x, &y, &r);

        longest = (double) sqrt((x * x) + (y * y)) + r;
        shortest = (double) (2 * r) - longest;

        printf("%.2lf %.2lf\n", shortest, longest);
    }
    return 0;
}
