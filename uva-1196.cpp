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

struct BLOCK
{
    int l;
    int m;

    bool operator<(const BLOCK &op)
    {
        if (l == op.l) {
            return m < op.m;
        }
        return l < op.l;
    }
};

vector<BLOCK>data;
int n; // number of data
int DP[MAX + 5]; // DP array for keeping the length of increasing sub-sequences
int direction[MAX + 5]; // Direction array to print the solution

int LIS(int current_index)
{
    if (DP[current_index] != -1) {
        return DP[current_index];
    }

    int maxLength = 0;
    for (int next_index = current_index + 1; next_index < n; next_index++) {
        if (data[next_index].l >= data[current_index].l && data[next_index].m >= data[current_index].m) {
            //maxLength = max(maxLength, LIS(next_index));
            if (LIS(next_index) > maxLength) {
                maxLength = LIS(next_index);
                direction[current_index] = next_index; // in solution, data[next_index] comes after data[current_index]
            }
        }
    }

    DP[current_index] = 1 + maxLength;
    return DP[current_index];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int start, i, ans, l, m;

    while (cin >> n) {
        if (!n) {
            break;
        }

        data.clear();
        memset(DP, -1, sizeof DP);
        memset(direction, -1, sizeof direction);

        for (i = 0; i < n; i++) {
            cin >> l >> m;
            data.push_back({l, m});
        }

        sort(data.begin(), data.end());

        ans = 0;
        for (i = 0; i < n; i++) {
            ans = max(ans, LIS(i));
        }

        cout << ans << "\n";
    }
    cout << "*\n";

    return 0;
}



