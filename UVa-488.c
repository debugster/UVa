#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, f, i, j, k;

    scanf("%d", &test);
    for (t = 1; t <= test; t++)
    {
        scanf("%d%d", &n, &f);

        for (k = 1; k <= f; k++)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }

            for (i = n - 1; i >= 1; i--)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
            if (t == test && k == f) {

            }
            else {
                printf("\n");
            }
        }

    }

    return 0;
}
