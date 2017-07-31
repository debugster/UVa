#include <stdio.h>
#include <math.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    double l, w, h, angle, half_angle, v, pi;
    pi = 2 * acos(0.0);

    while (scanf("%lf%lf%lf%lf", &l, &w, &h, &angle) != EOF) {
        angle = angle * pi / 180;
        half_angle = atan(h / l);

        if (fabs(angle - half_angle) < 0.000001) {
            v = l * w * h * 0.5;
        }
        else if (angle < half_angle) {
            v = (l * w * h) - (l * l * w * tan(angle) * 0.5);
        }
        else {
            v = (h * h * w) / (2 * tan(angle));
        }

        printf("%.3lf mL\n", v);
    }
    return 0;
}
