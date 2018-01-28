#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int Ax, Ay, Bx, By, Cx, Cy;
    double a, b, c, s, p, area, Ix, Iy, d, e, f, r, r1, r2, r3;

    while (scanf("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy)) {
        if (!Ax && !Ay && !Bx && !By && !Cx && !Cy) {
            break;
        }

        a = sqrt(pow(Bx - Cx, 2) + pow (By - Cy, 2));
        b = sqrt(pow(Ax - Cx, 2) + pow (Ay - Cy, 2));
        c = sqrt(pow(Bx - Ax, 2) + pow (By - Ay, 2));

        p = a + b + c;
        s = p / 2;

        area = sqrt(s * (s - a) * (s - b) * (s - c));
        r = (2 * area) / p;

        Ix = (a * Ax + b * Bx + c * Cx) / p;
        Iy = (a * Ay + b * By + c * Cy) / p;

        d = sqrt(pow(Ax - Ix, 2) + pow(Ay - Iy, 2));
        e = sqrt(pow(Bx - Ix, 2) + pow(By - Iy, 2));
        f = sqrt(pow(Cx - Ix, 2) + pow(Cy - Iy, 2));

        r1 = (r * (s + d - r - e - f)) / (2 * (s - a));
        r2 = (r * (s + e - r - d - f)) / (2 * (s - b));
        r3 = (r * (s + f - r - d - e)) / (2 * (s - c));

        printf("%.6lf %.6lf %.6lf\n", r1, r2, r3);
    }

    return 0;
}

