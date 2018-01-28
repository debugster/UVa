#include <bits/stdc++.h>
#define UP 'U'
#define CORNER 'C'
#define LEFT 'L'

using namespace std;

const int MAX = 100;

int Length[MAX + 1][MAX + 1]; /// table for length
//char Direction[MAX + 1][MAX + 1]; /// table for direction
int A[MAX + 1];
int B[MAX + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n1, n2, i, j, caseNo = 1;

    while (scanf("%d%d", &n1, &n2) && n1 != 0 && n2 != 0) {
        for (i = 1; i <= n1; i++) {
            scanf("%d", &A[i]);
        }
        for (j = 1; j <= n2; j++) {
            scanf("%d", &B[j]);
        }

        for (i = 1; i <= n1; i++) {
            for (j = 1; j <= n2; j++) {
                if (A[i] == B[j]) {
                    Length[i][j] = Length[i - 1][j - 1] + 1;
                    //Direction[i][j] = CORNER;
                }
                else {
                    if (Length[i - 1][j] >= Length[i][j - 1]) {
                        Length[i][j] = Length[i - 1][j];
                        //Direction[i][j] = UP;
                    }
                    else {
                        Length[i][j] = Length[i][j - 1];
                        //Direction[i][j] = LEFT;
                    }
                }
            }
        }

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", caseNo++, Length[n1][n2]);
    }

    return 0;
}

