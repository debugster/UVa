#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p, i, y1, y2, ansCount, ansY1, ansY2, _max;
    vector<int>all;
    vector<int>::iterator u, l;

    while (cin >> n) {
        cin >> p;
        all.clear();
        for (i = 0; i < p; i++) {
            cin >> y1;
            all.push_back(y1);
        }

        _max = -1;
        for (i = 0; i < p; i++) {
            y1 = all[i];
            y2 = all[i] + n - 1;

            u = upper_bound(all.begin(), all.end(), y2);
            l = lower_bound(all.begin(), all.end(), y1);
            ansCount = u - l;
            if (ansCount > _max) {
                _max = ansCount;
                ansY1 = y1;

                if (binary_search(all.begin(), all.end(), y2)) {
                    ansY2 = y2;
                }
                else {
                    u--;
                    ansY2 = all[u - all.begin()];
                }
            }
        }
        cout << _max << " " << ansY1 << " " << ansY2 << "\n";
    }

    return 0;
}


