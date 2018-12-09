#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 10000

/* macro ends */

/* function starts */

template<typename dataType>
dataType nthGrayCode(dataType n) /// n is 0-based
{
    return (n ^ (n >> 1));
}

/* function ends */

int _countR[MAX];
int _countC[MAX];
int moveR[] = {0, 0, 1, 0, -1};
int moveC[] = {0, 1, 0, -1, 0};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1, r, c, n, i, j, k, nextI, nextJ;
    bool escaped;

    while (scanf("%d%d%d", &r, &c, &n)) {
        if (!r && !c && !n) {
            break;
        }

        r--;
        c--;

        for (i = 0; i <= r; i++) {
            _countR[i] = 0;
        }
        for (i = 0; i <= c; i++) {
            _countC[i] = 0;
        }

        for (k = 1; k <= n; k++) {
            scanf("%d%d", &i, &j);
            _countR[i]++;
            _countC[j]++;
        }

        scanf("%d%d", &i, &j);
        escaped = false;
        for (k = 0; k <= 4; k++) {
            nextI = i + moveR[k];
            nextJ = j + moveC[k];

            if (nextI >= 0 && nextI <= r && nextJ >= 0 && nextJ <= c) {
                if (!_countR[nextI] && !_countC[nextJ]) {
                    escaped = true;
                    break;
                }
            }
        }
        if (escaped) {
            printf("Case %d: Escaped again! More 2D grid problems!\n", test++);
        }
        else {
            printf("Case %d: Party time! Let's find a restaurant!\n", test++);
        }
    }

    return 0;
}

