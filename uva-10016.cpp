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
#define MAX 105

/* macro ends */

int matrix[MAX][MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, c, flip, rings, i, j, k, m, p, r, limit;
    int lower, upper;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        rings = ceil(n / 2.0);
        for (r = 1; r <= rings; r++) {

            lower = r;
            upper = n - r + 1;

            scanf("%d", &c);
            for (k = 1; k <= c; k++) {
                scanf("%d", &flip);

                switch (flip)
                {
                case 1:

                    for (i = lower, j = upper, m = lower; m <= upper; m++) {
                        swap(matrix[i][m], matrix[j][m]);
                    }

                    //limit = ((lower + 1) + (upper - 1)) / 2;
                    limit = (lower + upper) / 2;
                    for (i = lower + 1, j = upper - 1; i <= limit; i++, j--) {
                        swap(matrix[i][lower], matrix[j][lower]);
                        swap(matrix[i][upper], matrix[j][upper]);
                    }

                    break;

                case 2:

                    for (i = lower, j = upper, m = lower; m <= upper; m++) {
                        swap(matrix[m][i], matrix[m][j]);
                    }

                    //limit = ((lower + 1) + (upper - 1)) / 2;
                    limit = (lower + upper) / 2;
                    for (i = lower + 1, j = upper - 1; i <= limit; i++, j--) {
                        swap(matrix[lower][i], matrix[lower][j]);
                        swap(matrix[upper][i], matrix[upper][j]);
                    }

                    break;

                case 3:

                    for (j = lower; j <= upper; j++) {
                        swap(matrix[lower][j], matrix[j][lower]);
                    }

                    for (j = lower + 1; j <= upper; j++) {
                        swap(matrix[upper][j], matrix[j][upper]);
                    }

                    break;

                case 4:

                    for (i = upper, j = lower; i >= lower; i--, j++) {
                        swap(matrix[lower][i], matrix[j][upper]);
                    }

                    for (i = lower + 1, j = upper - 1; i <= upper; i++, j--) {
                        swap(matrix[i][lower], matrix[upper][j]);
                    }

                    break;
                }
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                printf("%d", matrix[i][j]);

                if (j != n) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
