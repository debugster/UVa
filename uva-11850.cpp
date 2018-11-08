#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, d;
    vector<int>dist;
    bool possible;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        dist.clear();
        for (i = 1; i <= n; i++) {
            scanf("%d", &d);
            dist.push_back(d);
        }

        sort(dist.begin(), dist.end());
        possible = true;
        for (i = 0; i < dist.size() - 1; i++) {
            if (dist[i + 1] - dist[i] > 200) {
                possible = false;
                break;
            }
        }

        /// she has to go to destination and come back
        if (possible && 1422 - dist[dist.size() - 1] <= 100) {
            printf("POSSIBLE\n");
        }
        else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}
