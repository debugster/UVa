#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, x[5], y;
    bool valid;

    while (scanf("%d", &x[0]) != EOF) {
        for (i = 1; i < 5; i++) {
            scanf("%d", &x[i]);
        }

        valid = true;
        for (i = 0; i < 5; i++) {
            scanf("%d", &y);
            if (y == x[i]) {
                valid = false;
            }
        }

        if (valid) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }
    return 0;
}
