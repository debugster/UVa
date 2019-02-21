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

#define MAX_SIZE 105
#define INF 10000

int matrix[MAX_SIZE][MAX_SIZE];
int sumMatrix[MAX_SIZE][MAX_SIZE];
int row;
int col;

void calculateMatrixSum()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sumMatrix[i][j] = matrix[i][j];

            if (i > 0) {
                sumMatrix[i][j] += sumMatrix[i - 1][j];
            }
            if (j > 0) {
                sumMatrix[i][j] += sumMatrix[i][j - 1];
            }
            if (i > 0 && j > 0) {
                // avoiding double counting using Inclusion-Exclusion Principle
                sumMatrix[i][j] -= sumMatrix[i - 1][j - 1];
            }
        }
    }
}

// returns sum of the sub-matrix which starts at matrix[r1][c1] and ends at matrix[r2][c2]
// here, r1 <= r2 & c1 <= c2
int findSum(int r1, int c1, int r2, int c2)
{
    int ans = sumMatrix[r2][c2];

    if (r1 > 0) {
        ans -= sumMatrix[r1 - 1][c2];
    }
    if (c1 > 0) {
        ans -= sumMatrix[r2][c1 - 1];
    }
    if (r1 > 0 && c1 > 0) {
        ans += sumMatrix[r1 - 1][c1 - 1];
    }

    return ans;
}

// returns maximum sub-matrix sum possible
int findMaxSum()
{
    int maxSum = -INF;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = i; k < row; k++) {
                for (int l = j; l < col; l++) {
                    maxSum = max(maxSum, findSum(i, j, k, l));
                }
            }
        }
    }
    return maxSum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int test, b, i, j, r1, r2, c1, c2;

    cin >> test;
    while (test--) {
        cin >> row;
        col = row;

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                matrix[i][j] = 1;
            }
        }

        cin >> b;
        while (b--) {
            cin >> r1 >> c1 >> r2 >> c2;
            for (i = r1 - 1; i < r2; i++) {
                for (j = c1 - 1; j < c2; j++) {
                    matrix[i][j] = -INF;
                }
            }
        }

        calculateMatrixSum();
        cout << max(0, findMaxSum()) << "\n";
    }

    return 0;
}


