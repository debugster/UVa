#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 1025

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
    }
}

/* function ends */

int killed[MAX][MAX];

struct NODE
{
    int x;
    int y;
    int s;
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, d, n, i, j, k, x, y, s, ans;
    vector<NODE>all;

    cin >> test;
    while (test--) {
        cin >> d >> n;
        all.clear();
        for (i = 0; i < n; i++) {
            cin >> x >> y >> s;
            all.push_back({x, y, s});
        }

        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                killed[i][j] = 0;
            }
        }

        for (k = 0; k < n; k++) {
            x = all[k].x;
            y = all[k].y;
            s = all[k].s;

            for (i = x - d; i <= x + d; i++) {
                if (i < 0 || i >= MAX) {
                    continue;
                }
                for (j = y - d; j <= y + d; j++) {
                    if (j < 0 || j >= MAX) {
                        continue;
                    }

                    killed[i][j] += s;
                }
            }
        }

        ans = -1;
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (killed[i][j] > ans) {
                    ans = killed[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        cout << x << " " << y << " " << ans << "\n";
    }

    return 0;
}


