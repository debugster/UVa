#include <bits/stdc++.h>

using namespace std;

int wave[10010];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, peak;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        for (i = 1; i <= n; i++) {
            scanf("%d", &wave[i]);
        }
        wave[0] = wave[n];
        wave[n + 1] = wave[1];

        peak = 0;
        for (i = 1; i <= n; i++) {
            if ((wave[i - 1] < wave[i] && wave[i] > wave[i + 1]) || (wave[i - 1] > wave[i] && wave[i] < wave[i + 1])) {
                peak++;
            }
        }

        printf("%d\n", peak);
    }

    return 0;
}

