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

#define MAX_GARMENT 25
#define MAX_MODEL 25
#define MAX_MONEY 210

/*
isReachable[g][m] = true, iff any model of the g-th garment can be bought without exceeding budget limit,
                    and m = total amount of money spent in buying;
otherwise isReachable[g][m] = false
*/
bool isReachable[MAX_GARMENT][MAX_MONEY];

/*
price[g][0] = k, denotes that there are k models in garment g
and, price[g][1], price[g][2], ... , price[g][k] denotes the prices of respective models
*/
int price[MAX_GARMENT][MAX_MODEL];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int test, totalMoney, money, c, k, garmentType, model, ans;

    cin >> test;
    while (test--) {
        cin >> totalMoney >> c;
        for (garmentType = 1; garmentType <= c; garmentType++) {
            cin >> k;
            price[garmentType][0] = k; // total k models
            for (model = 1; model <= k; model++) {
                cin >> price[garmentType][model];
            }
        }

        memset(isReachable, false, sizeof isReachable);

        garmentType = 1;
        for (model = 1; model <= price[garmentType][0]; model++) {
            if (price[garmentType][model] <= totalMoney) {
                money = price[garmentType][model];
                isReachable[garmentType][money] = true; // model from garmentType can be bought
            }
        }

        for (garmentType = 2; garmentType <= c; garmentType++) {
            for (money = 0; money <= totalMoney; money++) {
                if (isReachable[garmentType - 1][money]) {
                    for (model = 1; model <= price[garmentType][0]; model++) {
                        if (money + price[garmentType][model] <= totalMoney) {
                            isReachable[garmentType][money + price[garmentType][model]] = true;
                        }
                    }
                }
            }
        }

        ans = -1;
        garmentType = c;
        for (money = 0; money <= totalMoney; money++) {
            if (isReachable[garmentType][money]) {
                ans = max(ans, money);
            }
        }

        if (ans == -1) {
            cout << "no solution\n";
        }
        else {
            cout << ans << "\n";
        }
    }

    return 0;
}


