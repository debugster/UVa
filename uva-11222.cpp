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
#define MAX 10005

/* macro ends */

bool solved[4][MAX]; /// [solver no][solved no]
vector<int>solvedList[4];
vector<int>unCommon[4];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, p, p1, p2, s, i, v, _max;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {

        for (p = 1; p <= 3; p++) {
            solvedList[p].clear();
            for (i = 1; i <= MAX; i++) {
                solved[p][i] = false;
            }
        }

        for (p = 1; p <= 3; p++) {
            scanf("%d", &s);
            for (i = 1; i <= s; i++) {
                scanf("%d", &v);
                solved[p][v] = true;
                solvedList[p].push_back(v);
            }

            sort(solvedList[p].begin(), solvedList[p].end());
        }

        /*
        printf("Case #%d\n", t);
        for (p = 1; p <= 3; p++) {
            printf("Player %d: ", p);
            for (i = 0; i < solvedList[p].size(); i++) {
                printf("%d ", solvedList[p][i]);
            }
            printf("\n");
        }
        */

        //printf("Case #%d\n", t);
        for (p = 1; p <= 3; p++) {
            if (p == 1) {
                p1 = 2;
                p2 = 3;
            }
            else if (p == 2) {
                p1 = 1;
                p2 = 3;
            }
            else {
                p1 = 1;
                p2 = 2;
            }

            unCommon[p].clear();
            for (i = 0; i < solvedList[p].size(); i++) {
                v = solvedList[p][i];
                if (!solved[p1][v] && !solved[p2][v] && !binary_search(unCommon[p].begin(), unCommon[p].end(), v)) {
                    unCommon[p].push_back(v);
                }
            }

            /*
            printf("Player %d: ", p);
            for (i = 0; i < unCommon[p].size(); i++) {
                printf("%d ", unCommon[p][i]);
            }
            printf("\n");
            */
        }

        _max = max(unCommon[1].size(), max(unCommon[2].size(), unCommon[3].size()));
        //printf("MAX = %d\n", _max);

        printf("Case #%d:\n", t);
        for (p = 1; p <= 3; p++) {
            if (unCommon[p].size() == _max) {
                printf("%d ", p);

                printf("%d", _max);
                for (i = 0; i < _max; i++) {
                    printf(" %d", unCommon[p][i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
