#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, j, g;

    /*
    int DP[501];

    for (n = 2; n <= 500; n++) {
        g = 0;

        for (i = 1; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                g += __gcd(i, j);
            }
        }

        DP[n] = g;
    }
    */

    while (scanf("%d", &n) && n != 0) {

        g = n - 1;

        for (i = 2; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                g += __gcd(i, j);
            }
        }

        printf("%d\n", g);
        //printf("%d\n", DP[n]);
    }
    return 0;
}
