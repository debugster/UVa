#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, t, n, i, *age;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);

        age = (int *) malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            scanf("%d", &age[i]);
        }

        printf("Case %d: %d\n", t, age[n / 2]);
    }

    return 0;
}

