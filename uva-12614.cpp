#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, i, j, maxAND, number[30];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &number[i]);
        }

        maxAND = 0;
        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                maxAND = max(maxAND, (number[i] & number[j]));
            }
        }
        printf("Case %d: %d\n", t, maxAND);
    }

    return 0;
}

