/*UVA-10432*/

#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)

int main()
{
    double r, n, area;
    while(scanf("%lf%lf", &r, &n) != EOF) {
        area=((n * pow(r, 2.0)) / 2) * sin(360 / (n * 57.2957795));
            //area=((n * r * r * sin((2 * pi) / n)) / 2);
        printf("%0.3lf\n", area);
    }
    return 0;
}
