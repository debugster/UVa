/* http://ken.duisenberg.com/potw/archive/arch98/981113sol.html */

#include <stdio.h>
#include <math.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    double p, s, pi = pi = 2 * acos(0.0);
    while (scanf("%lf", &p) != EOF) {
        s = (p * sin(108 * pi / 180)) / sin(63 * pi / 180);
        printf("%.10lf\n", s);
    }
    return 0;
}
