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

    int test, n, m, i, k, p, limit, wo;
    string current, _new;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &m);

        p = 1 << n;
        current = "";
        for (i = 1; i <= p; i++) {
            current += '1';
        }

        for (i = 1; i <= m; i++) {
            scanf("%d", &k);
            current[k - 1] = '0';
        }

        wo = 0;
        for (i = n; i >= 1; i--) {
            limit = (1 << i);
            //limit = current.size();
            _new = "";
            for (k = 0; k < limit; k += 2) {
                if (current[k] == '0' && current[k + 1] == '0') {
                    _new += '0';
                }
                else if (current[k] == '1' && current[k + 1] == '1') {
                    _new += '1';
                }
                else {
                    _new += '1';
                    wo++;
                }
                //printf("%s\n", _new.c_str());
            }
            //current.clear();
            //printf("i = %d limit = %d => current: %s new: %s\n", i, limit, current.c_str(), _new.c_str());
            current = _new;
        }

        printf("%d\n", wo);
    }

    return 0;
}
