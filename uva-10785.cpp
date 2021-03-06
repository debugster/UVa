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

int frequency[200];
char vowel[] = "AUEOI";
char consonant[] = "JSBKTCLDMVNWFXGPYHQZR";

int type(char ch)
{
    switch(ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return 1;
    default:
        return 2;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    string name, ans;
    int test, t, n, i, j, ptrV, ptrC;

    for (i = 0; i < 200; i++) {
        frequency[i] = 0;
    }

    name = "";
    ptrV = ptrC = 0;
    for (i = 1; i <= 210; i++) {
        if (i & 1) {
            // vowel
            while (true) {
                if (frequency[vowel[ptrV]] < 21) {
                    frequency[vowel[ptrV]]++;
                    name += vowel[ptrV];
                    break;
                }
                ptrV++;
            }
        }
        else {
            // consonant
            while (true) {
                if (frequency[consonant[ptrC]] < 5) {
                    frequency[consonant[ptrC]]++;
                    name += consonant[ptrC];
                    break;
                }
                ptrC++;
            }
        }
    }

    //cout << name << "\n";

    cin >> test;
    for (t = 1; t <= test; t++) {
        cin >> n;
        ans = name.substr(0, n);

        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (type(ans[i]) == type(ans[j]) && ans[i] > ans[j]) {
                    swap(ans[i], ans[j]);
                }
            }
        }

        cout << "Case " << t << ": " << ans << "\n";
    }


    return 0;
}


