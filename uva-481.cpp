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
Tutorial : http://www.lightoj.com/article_show.php?article=1000
*/

const int INF = 2000000000; // a large value as infinity
int n; // the number of items in the sequence
vector<int>data; // the sequence of given integers
vector<int>L; // L[] as described in the algorithm
vector<int>I; // I[] as described in the algorithm
vector<int>LIS; // for storing the sequence


// which runs the NlogK LIS algorithm
int LISNlogK()
{
    int i; // auxiliary variable for iteration
    I[0] = -INF; // I[0] = -infinite

    // observe that i <= n are given
    for(i = 1; i <= n; i++) {
        I[i] = INF; // I[1 to n] = infinite
    }

    for (i = 0; i < n; i++) {
        L[i] = n;
    }

    int LisLength = 0; // keeps the maximum position where a data is inserted

    // iterate left to right
    for(i = 0; i < n; i++) {
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while(low <= high) { // binary search to find the correct position
            mid = (low + high) / 2;
            if(I[mid] < data[i]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // observe the binary search carefully, when the binary search ends,
        // low > high and we put our item in I[low]
        I[low] = data[i];
        L[i] = low;

        // LisLength contains the maximum position
        if(LisLength < low) {
            LisLength = low;
        }
    }

    return LisLength; // return the result
}

// prints a valid LIS
void printLIS(int maxLength)
{
    int i, j; // variable used for iteration

    // at first find the position of the item whose L[] is maximum
    i = 0;
    for(j = 1; j < n; j++) {
        if(L[j] >= L[i]) {
            i = j;
        }
    }

    // initialize the position in LIS where the items can be added.
    // observe that the data are saving from right to left!
    int top = L[i] - 1;

    // insert the item in i-th position to LIS
    LIS[top] = data[i];
    top--; // is decreasing such that a new item can be added in a new place

    // now find the other valid numbers to form the sequence
    for(j = i - 1; j >= 0; j--) {
        if(data[j] < data[i] && L[j] == L[i] - 1) {
            // we have found a valid item so, we will save it
            i = j; // as in our algorithm
            LIS[top] = data[i]; // stored
            top--; // decreased for new items
        }
    }

    // so, we have got the sequence, now we want to print it
    for(i = 0; i < maxLength; i++) {
        cout << LIS[i] << "\n";
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int x, ans;
    while (cin >> x) {
        data.push_back(x);
    }

    n = (int) data.size();

    I.assign(n + 1, 0);
    L.assign(n + 1, 0);
    LIS.assign(n + 1, 0);

    ans = LISNlogK();

    /*
    for (int i = 0; i < n; i++) {
        cout << data[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << L[i] << "\t";
    }
    cout << "\n";
    */

    cout << ans << "\n-\n";
    printLIS(ans);

    return 0;
}
