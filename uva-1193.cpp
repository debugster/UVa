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

struct INTERVAL
{
    double l;
    double r;

    bool operator<(const INTERVAL &in)
    {
        if (fabs(r - in.r) < EPS) {
            return l < in.l;
        }
        return r < in.r;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int test = 1, n, i, ans;
    double d, x, y, dx, currentRadarX;
    vector<INTERVAL>all;

    while (cin >> n >> d) {
        if (!n) {
            break;
        }

        ans = 0;
        all.clear();
        for (i = 0; i < n; i++) {
            cin >> x >> y;
            if (y > d) {
                // in this case, no radar can cover this island
                ans = -1;
            }
            else {
                dx = sqrt((d * d) - (y * y));
                all.push_back({x - dx, x + dx});
            }
        }

        /*
        sort(all.begin(), all.end());
        for (i = 0; i < n; i++) {
            cout << setprecision(2) << fixed << all[i].l << " " << all[i].r << "\n";
        }
        */

        if (ans != -1) {
            sort(all.begin(), all.end());
            ans = 0;
            i = 0;
            currentRadarX = -1e9;
            while (i < n) {
                while (all[i].l <= currentRadarX && i < n) {
                    currentRadarX = min(currentRadarX, all[i].r);
                    i++;
                }
                currentRadarX = all[i].r;
                ans++;
            }
            cout << "Case " << test++ << ": " << ans - 1 << "\n";
        }
        else {
            cout << "Case " << test++ << ": " << ans << "\n";
        }
    }

    return 0;
}


