#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
//const double PI = 4 * atan(1.0); /// RUN TIME : 0.090
const double PI = acos(-1.0); /// RUN TIME : 0.070
//const double PI = 3.14159265358979323846; /// RUN TIME : 0.070

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int test;
    double b, h, b_prime, h_prime, r, sum;

    scanf("%d", &test);
    while (test--) {

        scanf("%lf%lf", &b, &h);

        sum = 0;

        while (1) {
            r = tan(atan((2 * h) / b) / 2) * (b / 2);

            if (r < EPS) {
                break;
            }

            sum += 2 * PI * r;
            h_prime = h - 2 * r;
            b_prime = (b * h_prime) / h;

            h = h_prime;
            b = b_prime;
        }

        printf("%13.6lf\n", sum);

        /// Printing a blank line between consecutive test cases except the last test case
        if (test) {
            printf("\n");
        }
    }

    return 0;
}
