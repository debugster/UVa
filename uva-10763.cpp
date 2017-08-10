/// RT : 0.050s

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 500000;

int DOMESTIC[SIZE + 1];
int FOREIGN[SIZE + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, d, f;
    bool possible;

    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }

        for (i = 1; i <= n; i++) {
            scanf("%d%d", &d, &f);
            DOMESTIC[d]++;
            FOREIGN[f]++;
        }

        possible = true;
        for (i = 1; i <= SIZE; i++) {
            if (DOMESTIC[i] != FOREIGN[i]) {
                possible = false;
            }
            /// Resetting to 0 for the next use
            /// Avoiding function to do so to reduce run time
            DOMESTIC[i] = FOREIGN[i] = 0;
        }

        if (possible) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
