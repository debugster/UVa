#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX  65540

/* macro ends */

int frequency[MAX];
vector<int>data;

void initialize()
{
    data.clear();
    for (int i = 0; i < MAX; i++) {
        frequency[i] = 0;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, x, median, low, high, lowV, highV, diff, _count;

    while (scanf("%d", &n) != EOF) {
        initialize();

        for (i = 1; i <= n; i++) {
            scanf("%d", &x);
            data.push_back(x);
            frequency[x]++;
        }

        sort(data.begin(), data.end());

        /// n is odd
        if (n & 1) {
            median = data[n / 2];
            _count = frequency[median];
            diff = 1;
        }
        /// n is even
        else {
            high = n / 2;
            low = high - 1;

            highV = data[high];
            lowV = data[low];

            if (lowV == highV) {
                median = lowV;
                _count = frequency[lowV];
                diff = 1;
            }
            else {
                median = min(lowV, highV);
                _count = frequency[lowV] + frequency[highV];
                diff = highV - lowV + 1;
            }
        }

        printf("%d %d %d\n", median, _count, diff);
    }

    return 0;
}
