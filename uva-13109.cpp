#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, m, w, maxW, i, sum, count, *weights;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &m, &maxW);

        weights = (int *) malloc(m * sizeof(int));
        for (i = 0; i < m; i++) {
            scanf("%d", &weights[i]);
        }

        sort(weights, weights + m);

        for (i = 0, count = 0, sum = 0; i < m; i++) {
            sum += weights[i];

            if (sum <= maxW) {
                count++;
            }
            else {
                break;
            }
        }

        printf("%d\n", count);
        free(weights);
    }
    return 0;
}
