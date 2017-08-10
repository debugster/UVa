#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, a;

    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }

        vector<int>ages;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a);
            ages.push_back(a);
        }

        sort(ages.begin(), ages.end());
        a = ages.size() - 1;
        for (i = 0; i < a; i++) {
            printf("%d ", ages[i]);
        }
        printf("%d\n", ages[i]);
    }
    return 0;
}
