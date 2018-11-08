#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */



int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    double aT; /// area of triangle
    double aIC; /// area of inner circle
    double aOC; /// area of outer circle
    double s; /// semi-perimeter of triangle
    double r1; /// radius of outer circle
    double r2; /// radius of inner circle
    double rose; /// inner circle
    double violet; /// triangle - inner circle
    double sunFlower; /// outer circle - triangle

    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {
        s = (a + b + c) / 2.0;
        aT = sqrt(s * (s - a) * (s - b) * (s - c));

        /// a * b * c = radius of outer circle * sqrt((a+b+c)(a+b-c)(b+c-a)(c+a-b))
        r1 = (a * b * c * 1.0) / sqrt((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b));
        /// area of triangle = radius of inner circle * semi-perimeter of triangle
        r2 = aT / s;
        aIC = PI * r2 * r2;
        aOC = PI * r1 * r1;

        rose = aIC;
        violet = aT - aIC;
        sunFlower = aOC - aT;

        printf("%.4lf %.4lf %.4lf\n", sunFlower, violet, rose);
    }

    return 0;
}
