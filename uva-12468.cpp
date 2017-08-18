#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int a, b, moveUp, moveDown, diff, MIN;

    while (scanf("%d%d", &a, &b) != EOF) {
        if (a == -1 && b == -1) {
            break;
        }

        if (a == 0 && b == 99 || a == 99 && b == 0) {
            printf("1\n");
        }
        else {
            moveUp = 99 - a + b + 1;
            moveDown = a + 99 - b + 1;
            diff = abs(a - b);

            MIN = min(diff, min(moveUp, moveDown));
            printf("%d\n", MIN);
        }

    }
    return 0;
}
