#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, n, DP[101];

    DP[0] = 0;
    for (i = 1; i <= 100; i++) {
        DP[i] = (i * i) + DP[i - 1];
    }

    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }

        printf("%d\n", DP[n]);
    }
    return 0;
}
