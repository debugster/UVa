#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 101

/* macro ends */

/* function starts */

template<typename dataType>
dataType nthGrayCode(dataType n) /// n is 0-based
{
    return (n ^ (n >> 1));
}

/* function ends */

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, s, q, qi, totalQI, i, j, c, _count, timeTaken;
    stack<int>carrier;
    queue<int>Q[MAX];

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d%d", &n, &s, &q);

        totalQI = 0;
        for (i = 1; i <= n; i++) {
            while (!Q[i].empty()) {
                Q[i].pop();
            }

            scanf("%d", &qi);
            for (j = 1; j <= qi; j++) {
                scanf("%d", &c);
                Q[i].push(c);
            }
            totalQI += qi;
        }

        while (!carrier.empty()) {
            carrier.pop();
        }

        _count = 0;
        timeTaken = 0;
        for (i = 1; i <= n; i++) {

            /// unload carrier
            while (true) {
                if (carrier.empty()) {
                    break;
                }

                c = carrier.top();
                if (c == i) {
                    carrier.pop();
                    timeTaken++;
                    _count++;
                }
                else {
                    if (Q[i].size() < q) {
                        carrier.pop();
                        Q[i].push(c);
                        timeTaken++;
                    }
                    else {
                        break;
                    }
                }
            }

            /// load carrier
            while (true) {
                if (carrier.size() == s || Q[i].empty()) {
                    break;
                }

                c = Q[i].front();
                Q[i].pop();
                carrier.push(c);
                timeTaken++;
            }

            if (_count == totalQI) {
                break;
            }

            if (i == n) {
                i = 0; /// after increment, it will be 1
            }
            timeTaken += 2;
        }

        printf("%d\n", timeTaken);
    }

    return 0;
}

