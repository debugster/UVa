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
#define MAX 200005

/* macro ends */

int p[MAX];
int q[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, i, limit, start;
    ll pSum, qSum;
    bool possible;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);

        pSum = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            p[i + n] = p[i];
            pSum += (ll) p[i];
        }
        qSum = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &q[i]);
            q[i + n] = q[i];
            qSum += (ll) q[i];
        }

        printf("Case %d: ", t);
        if (pSum >= qSum) {
            for (start = 1; start <= n; start++) {
                pSum = qSum = 0;
                limit = start + n;
                for (i = start; i <= limit; i++) {
                    pSum += (ll) p[i];
                    qSum += (ll) q[i];

                    if (qSum > pSum) {
                        break;
                    }
                }

                if (i == limit + 1) {
                    break;
                }
            }

            printf("Possible from station %d\n", start);
        }
        else {
            printf("Not possible\n");
        }
    }

    return 0;
}
