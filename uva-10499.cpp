#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long n;

    while (scanf("%lld", &n)) {
        if (n < 0) {
            break;
        }

        printf("%lld%%\n", n * (n == 1 ? 0 : 25));
    }

    return 0;
}

