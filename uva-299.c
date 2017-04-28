#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, L, count, i, j, temp, *t;
    scanf("%d", &test);

    while (test--) {
        scanf("%d", &L);
        t = (int *) malloc(L * sizeof(int));

        for (i = 0; i < L; i++) {
            scanf("%d", &t[i]);
        }

        count = 0;
        for (i = 0; i < L - 1; i++) {
            for (j = i + 1; j < L; j++) {
                if (t[i] > t[j]) {
                    count++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}
