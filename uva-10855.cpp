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
#define MAX 1005

/* macro ends */

char BIG[MAX][MAX];
char SMALL[MAX][MAX];
char temp[MAX][MAX];

/// rotates SMALL[][] by 90 degrees
void rotateBy90(int n);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n, i, j, i2, j2, i3, j3, r, _count[5];
    bool finish, found;

    while (scanf("%d%d", &N, &n)) {
        getchar();

        if (!N && !n) {
            break;
        }

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                scanf("%c", &BIG[i][j]);
            }
            getchar();
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%c", &SMALL[i][j]);
            }
            getchar();
        }

        for (r = 1; r <= 4; r++) {
            _count[r] = 0;

            if (r > 1) {
                rotateBy90(n);
            }

            /*///
            for (i = 1; i <= N; i++) {
                for (j = 1; j <= N; j++) {
                    printf("%c", BIG[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            ///*/

            for (i = 1; i <= N; i++) {
                finish = false;
                for (j = 1; j <= N; j++) {

                    if ((N - i + 1) < n) {
                        finish = true;
                        break;
                    }
                    if ((N - j + 1) < n) {
                        break;
                    }

                    found = true;
                    for (i2 = i, i3 = 1; i3 <= n; i2++, i3++) {
                        for (j2 = j, j3 = 1; j3 <= n; j2++, j3++) {
                            if (BIG[i2][j2] != SMALL[i3][j3]) {
                                found = false;
                                break;
                            }
                        }
                        if (!found) {
                            break;
                        }
                    }

                    if (found) {
                        _count[r]++;
                    }
                }
                if (finish) {
                    break;
                }
            }
        }

        for (i = 1; i <= 4; i++) {
            printf("%d", _count[i]);
            if (i == 4) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }

    return 0;
}

void rotateBy90(int n)
{
    int i, j, k;

    for (i = n, k = 1; i >= 1; i--, k++) {
        for (j = 1; j <= n; j++) {
            temp[j][k] = SMALL[i][j];
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            SMALL[i][j] = temp[i][j];
        }
    }
}
