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

struct AGENCY
{
    string name;
    int A;
    int B;
    int total;

    bool operator<(const AGENCY &op)
    {
        if (total == op.total) {
            return name < op.name;
        }
        return total < op.total;
    }
};

vector<AGENCY>all;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int test, t, n, m, l, i, a, b, current, half, rest;
    string str;
    char ch;

    cin >> test;
    for (t = 1; t <= test; t++) {
        all.clear();
        cin >> n >> m >> l;

        for (i = 0; i < l; i++) {

            str = "";
            while (cin >> ch) {
                if (ch == ':') {
                    break;
                }
                str += ch;
            }
            cin >> a >> ch >> b;
            all.push_back({str, a, b, 0});
        }

        for (i = 0; i < l; i++) {
            current = n;
            while (true) {
                if (current <= m) {
                    break;
                }

                half = ceil(current / 2.0);
                rest = current - half;
                if (rest > m) {
                    all[i].total += min(half * all[i].A, all[i].B);
                    current = rest;
                }
                else if (rest == m) {
                    rest = current - m;
                    all[i].total += min(rest * all[i].A, all[i].B);
                    //all[i].total += rest * all[i].A;
                    current -= rest;
                }
                else {
                    rest = current - m;
                    //all[i].total += min(rest * all[i].A, all[i].B);
                    all[i].total += rest * all[i].A;
                    current -= rest;
                }
            }
        }

        sort(all.begin(), all.end());
        cout << "Case " << t << "\n";
        for (i = 0; i < l; i++) {
            cout << all[i].name << " " << all[i].total << "\n";
        }
    }

    return 0;
}


