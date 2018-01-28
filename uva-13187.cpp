#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test;
    ULL s, n;

    scanf("%d", &test);
    while (test--) {
        scanf("%llu", &s);
        /// n = (s + 1)^2 - 1
        /// or, n = s * (s + 2)
        n = s * (s + 2);
        printf("%llu\n", n);
    }

    return 0;
}

