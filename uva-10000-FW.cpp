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

#define MAX 105

int adjMatrix[MAX][MAX];

// Floyd-Warshall modified
void FW(int nodes)
{
    int i, j, k;

    for (k = 1; k <= nodes; k++) {
        for (i = 1; i <= nodes; i++) {
            for (j = 1; j <= nodes; j++) {
                if (adjMatrix[i][k] != 0 && adjMatrix[k][j] != 0) {
                    if (adjMatrix[i][j] < adjMatrix[i][k] + adjMatrix[k][j]) {
                        adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    }
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int test = 1, n, i, s, f, p, q, ans;

    while (cin >> n) {
        if (!n) {
            break;
        }

        for (p = 1; p <= n; p++) {
            for (q = 1; q <= n; q++) {
                adjMatrix[p][q] = 0;
            }
        }

        cin >> s;
        while (cin >> p >> q) {
            if (!p) {
                break;
            }
            adjMatrix[p][q] = 1;
        }

        FW(n);
        ans = -1;
        f = n + 1;
        for (i = 1; i <= n; i++) {
            if (ans < adjMatrix[s][i]) {
                ans = adjMatrix[s][i];
                f = i;
            }
            else if (ans == adjMatrix[s][i]) {
                f = min(f, i);
            }
        }

        if (ans == 0) {
            f = s;
        }

        cout << "Case " << test++ << ": The longest path from "<< s << " has length " << ans << ", finishing at " << f << ".\n\n";
    }

    return 0;
}



