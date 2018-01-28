#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, m;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &m);

        if (n % 3 != 0) {
            n -= (n % 3);
        }
        if (m % 3 != 0) {
            m -= (m % 3);
        }

        printf("%d\n", (n * m) / 9);
    }

    return 0;
}

