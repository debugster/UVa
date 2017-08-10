#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, k, p;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d%d", &n, &k, &p);

        while (p--) {
            k++;

            if (k > n) {
                k = 1;
            }
        }

        printf("Case %d: %d\n", t, k);
    }

    return 0;
}
