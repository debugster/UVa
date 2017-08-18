#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int k, i, dX, dY, x, y;

    while (scanf("%d", &k)) {
        if (!k) {
            break;
        }

        scanf("%d%d", &dX, &dY);
        for (i = 1; i <= k; i++) {
            scanf("%d%d", &x, &y);
            x -= dX;
            y -= dY;

            if (x == 0 || y == 0) {
                printf("divisa\n");
            }
            else if (x > 0 && y > 0) {
                printf("NE\n");
            }
            else if (x > 0 && y < 0) {
                printf("SE\n");
            }
            else if (x < 0 && y < 0) {
                printf("SO\n");
            }
            /// else if (x < 0 && y > 0) {
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
