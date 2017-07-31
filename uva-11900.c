#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, n, p, q, count, sum, *egg;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d%d", &n, &p, &q);

        egg = (int *) malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            scanf("%d", &egg[i]);
        }

        i = count = sum = 0;

        while (i < n) {
            sum += egg[i++];

            if (sum <= q) {
                count++;
            }

            if (count >= p || sum >= q) {
                break;
            }
        }

        printf("Case %d: %d\n", t, count);
    }
    return 0;
}
