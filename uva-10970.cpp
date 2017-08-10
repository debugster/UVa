#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int m, n;

    while (scanf("%d%d", &m, &n) != EOF) {
        printf("%d\n", (m * n - 1));
    }
    return 0;
}
