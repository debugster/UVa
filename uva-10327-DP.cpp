#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int n, i, pos, minCount, data[1000];
    vector<int>DP;
    vector<int>::iterator p;

    while (scanf("%d", &n) != EOF) {

        DP.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
            DP.push_back(data[i]);
        }

        minCount = 0;

        sort(data, data + n);

        for (i = 0; i < n; i++) {
            p = find(DP.begin(), DP.end(), data[i]);
            pos = distance(DP.begin(), p);
            minCount += pos;
            DP.erase(p);
        }

        printf("Minimum exchange operations : %d\n", minCount);
    }

    return 0;
}
