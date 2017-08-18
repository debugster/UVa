#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<bool>List(1000000001, false);
    int n, m, i, count;
    unsigned long long x;

    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }

        List.assign(1000000001, false);

        for (i = 1; i <= n; i++) {
            scanf("%llu", &x);
            List[x] = true;
        }
        count = 0;
        for (i = 1; i <= m; i++) {
            scanf("%llu", &x);
            if (List[x]) {
                count++;
            }
        }
        printf("%d\n", count);
        List.clear();
    }

    return 0;
}

