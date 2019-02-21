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

/**
################ IDEA ################

1. Basic idea: To minimise time, the second guy (GolapiBaba) should be kept as less idle as possible, since the first guy (Sultan) is never going to be idle until he has finished doing all problems.
2. Let for problem p(i), first guy take a(i) time and second guy take b(i) time.
3. We wanna put as much a huge workload as possible on the second guy initially, so that later on, he is not idle.
4. This can only happen if the initial problems have a(i) < b(i), i.e., first guy does less work, but the second has to do more.
5. Also, for problems with a(i) < b(i), problem with least a(i) should be solved first, since we don't wanna keep the second guy waiting for too long initially.
6. Now for the problems with a(i) >= b(i). We can hope that the second guy still has some backlog from solving the previous problems with a(i) < b(i). But to ensure he is never idle, we should pile him up with as much work as possible (even though that work <= the work of first guy).
7. Hence for the problems with a(i) >= b(i) the problems with greater b(i) should be solved first.

Credit: Batman
*/

struct PROBLEM
{
    int s;
    int g;

    bool operator<(const PROBLEM &p)
    {
        if (s < g && p.s < p.g) {
            return s <= p.s;
        }
        else if (s < g) {
            return true;
        }
        else if (p.s < p.g) {
            return false;
        }

        if (s >= g && p.s >= p.g) {
            return g >= p.g;
        }
        else if (s >= g) {
            return true;
        }
        else {
            return false;
        }
    }
};

vector<PROBLEM>all;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int n, i, t;
    vector<int>timeline;

    while (cin >> n) {
        all.clear();

        for (i = 0; i < n; i++) {
            cin >> t;
            all.push_back({t, 0});
        }
        for (i = 0; i < n; i++) {
            cin >> t;
            all[i].g = t;
        }

        sort(all.begin(), all.end());

        t = 0;
        timeline.clear();
        for (i = 0; i < n; i++) {
            t += all[i].s;
            timeline.push_back(t);
        }

        for (i = 0, t = 0; i < n; i++) {
            t = max(t + all[i].g, timeline[i] + all[i].g);
        }
        cout << t << "\n";
    }

    return 0;
}


