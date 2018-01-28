#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int w, h, n, i, j, x, x1, x2, LimX, y, y1, y2, LimY, count, total;
    bool matrix[501][501];

    while (scanf("%d%d%d", &w, &h, &n)) {
        if (!w && !h && !n) {
            break;
        }

        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                matrix[i][j] = false;
            }
        }

        count = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

            //x = min(x1, x2);
            LimX = max(x1, x2);

            //y = min(y1, y2);
            LimY = max(y1, y2);

            for (y = min(y1, y2); y <= LimY; y++) {
                for (x = min(x1, x2); x <= LimX; x++) {
                    if (matrix[y][x] == false) {
                        matrix[y][x] = true;
                        count++;
                    }
                }
            }
        }

        total = w * h - count;
        if (total == 0) {
            printf("There is no empty spots.");
        }
        else if (total == 1) {
            printf("There is one empty spot.");
        }
        else {
            printf("There are %d empty spots.", total);
        }
        printf("\n");
    }

    return 0;
}

