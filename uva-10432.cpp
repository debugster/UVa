#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    double r, n, area;
    while(scanf("%lf%lf", &r, &n) != EOF) {
        //area=((n * pow(r, 2.0)) / 2) * sin(360 / (n * 57.2957795));
        area=((n * r * r * sin((2 * PI) / n)) / 2);
        printf("%0.3lf\n", area);
    }
    return 0;
}
