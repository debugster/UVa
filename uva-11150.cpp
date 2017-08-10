#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;

    while (scanf("%d", &n) != EOF) {
        printf("%d\n", n + n / 2);
    }
    return 0;
}
