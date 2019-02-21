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
Formula: https://www.xarg.org/2016/07/calculate-the-intersection-area-of-two-circles/
*/

double R, P, r, area, x, y;

double fX(double root)
{
    double ans;

    x = ((2 * R * R) - (root * root)) / (2 * R);
    y = sqrt((R * R) - (x * x));
    ans = (R * R * asin(y / R)) + (root * root * asin(y / root)) - (y * (x + sqrt((root * root) - (R * R) + (x * x)))) - area;
    return ans;
}

double Secant()
{
    double root, root1, root2, f1, f2;
    root1 = 0.01 * R;
    root2 = R;

    while (true) {
        f1 = fX(root1);
        f2 = fX(root2);
        root = root2 - (f2 * (root2 - root1)) / (f2 - f1);
        if (fabs(root - root2) > EPS) {
            root1 = root2;
            root2 = root;
        }
        else {
            break;
        }
    }
    return root;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int test, t;

    cin >> test;
    for (t = 1; t <= test; t++) {
        cin >> R >> P;

        area = PI * R * R * P;
        if (fabs(P - 0.0) > EPS) {
            r = Secant();
        }
        else {
            r = 0;
        }

        if (t != 1) {
            cout << "\n";
        }

        cout << "R = " << setprecision(0) << fixed << R << ", P = " << setprecision(2) << fixed << P << ", Rope = " << setprecision(2) << fixed << r << "\n";
    }

    return 0;
}


