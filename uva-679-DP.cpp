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

int DP[21][524290];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, d, i, l, r, current, _count, nodes, leaf;
    vector<bool>tree;

    for (d = 1; d <= 20; d++) {
        nodes = 1 << d;
        leaf = (nodes + 1) >> 1; /// leaf nodes = (total nodes + 1) / 2;

        tree.clear();
        tree.assign(nodes, false);

        for (i = 1; i <= leaf; i++) {

            _count = 1;
            current = 1;

            while (_count != d) {
                l = current << 1;
                r = l + 1;

                if (tree[current]) {
                    tree[current] = !tree[current];
                    current = r;
                }
                else {
                    tree[current] = !tree[current];
                    current = l;
                }
                _count++;
            }
            DP[d][i] = current;
        }
    }

    cin >> test;
    while (test--) {
        cin >> d >> i;
        cout << DP[d][i] << "\n";
    }
    cin >> test;

    return 0;
}



