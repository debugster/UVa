#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

/* function starts */

template<typename dataType>
dataType nthGrayCode(dataType n) /// n is 0-based
{
    return (n ^ (n >> 1));
}

/* function ends */

vector<pii>all;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j, k, l, startX, endX, startY, endY;
    bool conflict;

    while (scanf("%d%d", &n, &m)) {
        if (!n && !m) {
            break;
        }

        conflict = false;

        all.clear();

        for (i = 0; i < n; i++) {
            scanf("%d%d", &startX, &endX);
            all.push_back(make_pair(startX, endX));
        }



        for (i = 0; i < m; i++) {
            scanf("%d%d%d", &startX, &endX, &l);
            for (j = 0; ; j++) {
                startY = startX + l * j;
                endY = endX + l * j;

                if (startY >= 1000000) {
                    break;
                }

                all.push_back(make_pair(startY, endY));
            }
        }

        sort(all.begin(), all.end());
        conflict = false;
        //n += m;
        for (i = 1; i < all.size(); i++) {
            //if (all[i].first < all[i - 1].second && all[i].first >= all[i - 1].first) {
            if (all[i].first < all[i - 1].second) {
                conflict = true;
                break;
            }
        }

        conflict ? printf("CONFLICT\n") : printf("NO CONFLICT\n");
    }
    return 0;
}

