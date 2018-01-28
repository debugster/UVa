#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char r;
    double rectangle[11][4]; /// 0 - Ax, 1 - Ay, 2 - Cx, 3 - Cy
    double pX, pY;
    int i, j, count, p = 1, n = 0;

    while (r = getchar()) {
        if (r == '*') {
            break;
        }

        n++;
        for (i = 0; i <= 3; i++) {
            scanf("%lf", &rectangle[n][i]);
        }
        getchar();
    }

    /*
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 3; j++) {
            printf("%.1lf ", rectangle[i][j]);
        }
        putchar('\n');
    }
    */

    while (scanf("%lf%lf", &pX, &pY)) {
        if (fabs(pX - 9999.9) < EPS && fabs(pY - 9999.9) < EPS) {
            break;
        }

        //printf("%.1lf %.1lf\n", pX, pY);

        count = 0;
        for (i = 1; i <= n; i++) {
            if (pX > rectangle[i][0] && pX < rectangle[i][2] && pY < rectangle[i][1] && pY > rectangle[i][3]) {
                printf("Point %d is contained in figure %d\n", p, i);
                count++;
            }
        }

        if (!count) {
            printf("Point %d is not contained in any figure\n", p);
        }
        p++;
    }

    return 0;
}

