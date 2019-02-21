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
    int l;
    int r;

    bool operator<(const INTERVAL &in)
    {
        if (l == in.l) {
            return r > in.r;
        }
        return l < in.l;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int L, G, x, r, cover, currentRight, i, ans;
    vector<INTERVAL>all;

    while (cin >> L >> G) {
        if (!L) {
            break;
        }

        all.clear();
        for (i = 0; i < G; i++) {
            cin >> x >> r;
            all.push_back({max(0, x - r), x + r});
        }

        sort(all.begin(), all.end());

        /*
        for (i = 0; i < all.size(); i++) {
            cout << all[i].l << " " << all[i].r << "\n";
        }
        cout << "\n";
        */


        i = 0;
        cover = 0;
        ans = 0;
        currentRight = -1e6;
        while (true) {
            if (i >= all.size() || all[i].l > L || all[i].l > cover || cover >= L) {
                break;
            }

            if (all[i].r <= 0) {
                i++;
                continue;
            }

            while ((all[i].l <= cover || all[i].r <= cover) && i < all.size()) {
                if (all[i].l <= cover && all[i].r > currentRight) {
                    currentRight = all[i].r;
                }

                i++;
            }

            cover = currentRight;
            ans++;
        }

        if (cover < L) {
            cout << -1 << "\n";
        }
        else {
            cout << G - ans << "\n";
        }
    }

    return 0;
}


