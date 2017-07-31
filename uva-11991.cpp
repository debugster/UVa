#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m, i, j, count, k, v, d, row, col;
    char c;
    vector<vector<int> > data;

    while (scanf("%d%d", &n, &m) != EOF) {

        data.assign(1000000, vector<int>());

        for (i = 0; i < n; i++) {
            scanf("%d", &d);
            data[d - 1].push_back(i + 1);
        }

        for (i = 1; i <= m; i++) {
            scanf("%d%d", &k, &v);

            if (data[v - 1].size() >= k) {
                printf("%d\n", data[v - 1][k - 1]);
            }
            else {
                printf("0\n");
            }
        }
    }

    return 0;
}

