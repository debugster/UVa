#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, i, park, mid, total, places[21];

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);

        for (i = 1; i <= n; i++) {
            scanf("%d", &places[i]);
        }

        sort(places + 1, places + n + 1);

        mid = (n + 1) / 2;
        if (n & 1) {
            park = places[mid];
        }
        else {
            park = (places[mid] + places[mid + 1]) / 2;
        }
        total = 2 * (park - places[1]) + 2 * (places[n] - park);

        printf("%d\n", total);
    }

    return 0;
}

