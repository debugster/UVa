//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

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

#define MAX 100000

vector<int>all;
int DP[MAX];

// length of longest decreasing subsequence
int LDS(int u)
{
    if (DP[u] != -1) {
        return DP[u];
    }

    int _max = 0;
    for (int v = u + 1; v < all.size(); v++) {
        if (all[u] >= all[v]) {
            _max = max(_max, LDS(v));
        }
    }

    DP[u] = 1 + _max;
    return DP[u];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int n, test = 1, i, ans;

    while (cin >> n) {
        if (n != -1) {
            all.push_back(n);
        }
        else {
            if (all.size() == 0) {
                break;
            }

            memset(DP, -1, sizeof DP);
            ans = 0;
            for (i = 0; i < all.size(); i++) {
                ans = max(ans, LDS(i));
            }

            if (test != 1) {
                cout << "\n";
            }

            cout << "Test #" << test++ << ":\n  maximum possible interceptions: " << ans << "\n";

            all.clear();
        }
    }

    return 0;
}

