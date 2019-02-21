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
#define EPS 1e-7
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

vector<double> QuotientPolynomial(int degree, double root, vector<double>p_X)
{
    vector<double>q_X(degree + 1, 0.0);
    for (int i = degree - 1; i >= 0; i--) {
        q_X[i] = p_X[i + 1] + root * q_X[i + 1];
    }
    return q_X;
}

double fX(int degree, double x, vector<double>p_X)
{
    double ans = 0.0;
    for (int i = degree; i >= 0; i--) {
        ans += p_X[i] * pow(x, i);
    }
    return ans;
}

double dX(int degree, double x, vector<double>p_X)
{
    double ans = 0.0;
    for (int i = degree; i >= 1; i--) {
        ans += p_X[i] * i * pow(x, i - 1);
    }
    return ans;
}

double NewtonRaphson(int degree, vector<double>p_X)
{
    double x, x0;

    x0 = -25.0;
    while (true) {
        x = x0 - fX(degree, x0, p_X) / dX(degree, x0, p_X);
        if (fabs(x - x0) < EPS) {
            break;
        }
        x0 = x;
    }
    return x;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int n, i, test;
    double x;
    vector<double>allP, allRoot;

    cin >> test;
    while (test--) {
        cin >> n;

        allP.clear();
        allP.assign(n + 1, 0.0);
        for (i = n; i >= 0; i--) {
            cin >> allP[i];
        }

        for (i = n; i > 2; i--) {
            cin >> x;
            allP = QuotientPolynomial(i, x, allP);
        }

        allRoot.clear();
        for (i = 2; i >= 1; i--) {
            x = NewtonRaphson(i, allP);
            allRoot.push_back(x);
            allP = QuotientPolynomial(i, x, allP);
        }

        sort(allRoot.begin(), allRoot.end(), greater<double>());
        for (i = 0; i < allRoot.size(); i++) {
            cout << setprecision(1) << fixed << allRoot[i] << "\n";

        }
    }

    return 0;
}


