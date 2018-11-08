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
#define MAX_COIN 105

/* macro ends */

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, k, i, j, p, _count, f;
    int left[MAX_COIN], right[MAX_COIN];
    char ch;
    bool coins[MAX_COIN];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d", &n, &k);

        for (i = 1; i <= n; i++) {
            coins[i] = false;
        }

        for (i = 1; i <= k; i++) {
            scanf("%d", &p);

            for (j = 1; j <= p; j++) {
                scanf("%d", &left[j]);
            }
            for (j = 1; j <= p; j++) {
                scanf("%d", &right[j]);
            }
            getchar();
            scanf("%c", &ch);
            //printf("%c\n", ch);

            if (ch == '=') {
                for (j = 1; j <= p; j++) {
                    coins[left[j]] = coins[right[j]] = true;
                }
            }
        }

        _count = 0;
        for (i = 1; i <= n; i++) {
            if (!coins[i]) {
                _count++;
                f = i;
            }
        }

        if (t != 1) {
            printf("\n");
        }

        if (_count == 1) {
            printf("%d\n", f);
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}
