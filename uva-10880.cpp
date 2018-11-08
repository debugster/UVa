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

/* macro ends */



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n;
    ll c, r, x, i, j, limit;
    vector<ll>factors;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        printf("Case #%d:", t);
        scanf("%lld%lld", &c, &r);
        if (c == r) {
            printf(" 0\n");
            continue;
        }

        x = c - r;
        limit = sqrt(x);
        factors.clear();
        for (i = 1; i <= limit; i++) {
            if (x % i != 0) {
                continue;
            }

            j = x / i;
            if (i == j && i > r) {
                factors.push_back(i);
            }
            else if (i != j) {
                if (i > r) {
                    factors.push_back(i);
                }
                if (j > r) {
                    factors.push_back(j);
                }
            }
        }

        sort(factors.begin(), factors.end());
        for (n = 0; n < factors.size(); n++) {
            printf(" %d", factors[n]);
        }
        printf("\n");
    }

    return 0;
}
