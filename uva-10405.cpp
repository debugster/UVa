#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int Length[MAX + 1][MAX + 1]; /// table for length
char A[MAX + 5];
char B[MAX + 5];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m, i, j;

    while (gets(A)) {
        gets(B);

        n = strlen(A);
        m = strlen(B);

        for (i = n; i >= 0; i--) {
            A[i + 1] = A[i];
        }

        for (j = m; j >=0; j--) {
            B[j + 1] = B[j];
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (A[i] == B[j]) {
                    Length[i][j] = Length[i - 1][j - 1] + 1;
                }
                else {
                    if (Length[i - 1][j] >= Length[i][j - 1]) {
                        Length[i][j] = Length[i - 1][j];
                    }
                    else {
                        Length[i][j] = Length[i][j - 1];
                    }
                }
            }
        }

        printf("%d\n", Length[n][m]);
    }

    return 0;
}

