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

struct SEGMENT
{
    double l;
    double r;

    bool operator<(const SEGMENT &s)
    {
        if (fabs(l - s.l) < EPS) {
            return r > s.r;
        }
        return l < s.l;
    }
};

vector<SEGMENT>all;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, ans;
    double l, w, p, r, dx, dw, cover, currentRight;

    while (cin >> n >> l >> w) {
        all.clear();
        dw = w * w * 0.25;
        for (i = 0; i < n; i++) {
            cin >> p >> r;
            if (2.0 * r < w) {
                // if the given sprinkler has a diameter less than the width of the strip,
                // then, it will not cover the strip
                // so, store that sprinkler as a point, instead of a circle
                all.push_back({p, p});
            }
            else {
                dx = sqrt((r * r * 1.0) - dw);
                all.push_back({max(0.0, p - dx), p + dx});
            }

        }
        sort(all.begin(), all.end());

        cover = 0.0;
        ans = 0;
        i = 0;
        while (cover < l) {
            currentRight = -1.0;

            // if strip is not covered completely and there is no sprinklers remain
            if (i >= n) {
                ans = -1;
                break;
            }

            // iterate through sprinklers till they keep touching/intersecting the currently covered area
            while ((all[i].l <= cover || all[i].r <= cover) && i < n) {
                // if the sprinkler intersect the covered area
                if (all[i].l <= cover) {
                    currentRight = max(currentRight, all[i].r);
                }
                i++;
            }

            // if all the remaining sprinkler failed to increase the amount of covered area
            if (currentRight < cover) {
                ans = -1;
                break;
            }

            cover = currentRight;
            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}


