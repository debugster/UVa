#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, i, j, p, count, *h;
    char *days;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        days = (char *) malloc((n + 1) * sizeof(char));
        for (i = 1; i <= n; i++) {
            days[i] = 'w';
        }

        scanf("%d", &p);
        h = (int *) malloc(p * sizeof(int));
        for (i = 0; i < p; i++) {
            scanf("%d", &h[i]);
        }

        count = 0;
        for (i = 1; i <= n; i++) {
            for (j = 0; j < p; j++) {
                if (i % 7 != 0 && (i + 1) % 7 != 0) {
                    if (i % h[j] == 0) {
                        days[i] = 'x';
                        //count++;
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            if (days[i] == 'x') {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
