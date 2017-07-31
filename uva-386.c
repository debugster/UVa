#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int a, b, c, d, aCube, bCube, cCube, dCube;

    for (a = 6; a <= 200; a++) {
        aCube = a * a * a;
        for (b = 2; b < a; b++) {
            bCube = b * b * b;
            for (c = b; c < a; c++) {
                cCube = c * c * c;
                for (d = c; d < a; d++) {
                    dCube = d * d * d;
                    if (aCube == bCube + cCube + dCube) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}
