#include <bits/stdc++.h>
#define MAX 20

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int B, N, D, C, V, i;
    int R[MAX + 1];
    bool possible;

    while (scanf("%d%d", &B, &N), (B && N)) {
        for (i = 1; i <= B; i++) {
            scanf("%d", &R[i]);
        }

        for (i = 1; i <= N; i++) {
            scanf("%d%d%d", &D, &C, &V);
            R[D] -= V;
            R[C] += V;
        }

        possible = true;
        for (i = 1; i <= B; i++) {
            if (R[i] < 0) {
                possible = false;
                break;
            }
        }

        printf("%s\n", possible ? "S" : "N");
    }

    return 0;
}

