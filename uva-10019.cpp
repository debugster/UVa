#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test;
    long long n, m;
    char str[20];

    scanf("%d", &test);
    while (test--) {
        scanf("%lld", &n);
        sprintf(str, "%lld", n);
        m = strtoll(str, NULL, 16);

        printf("%d %d\n", __builtin_popcount(n), __builtin_popcount(m));
    }

    return 0;
}

