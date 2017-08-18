#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int r, n, m, i, test = 1;

    while (scanf("%d%d", &r, &n)) {
        if (!r && !n) {
            break;
        }

        printf("Case %d: ", test++);

        if (n >= r) {
            printf("0\n");
            continue;
        }

        if (r % n == 0) {
            m = r / n - 1;
        }
        else {
            m = r / n;
        }

        if (m > 26) {
            printf("impossible\n");
        }
        else {
            printf("%d\n", m);
        }
    }

    return 0;
}

