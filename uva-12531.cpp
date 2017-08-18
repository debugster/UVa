#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;

    while (scanf("%d", &n) != EOF) {
        n % 6 == 0 ? printf("Y\n") : printf("N\n");
    }
    return 0;
}
