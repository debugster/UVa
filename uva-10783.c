#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, a, b, sum;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d", &a, &b);

        sum = 0;
        for (i = a; i <= b; i++) {
            if (i % 2 == 1) {
                sum += i;
            }
        }

        printf("Case %d: %d\n", t, sum);
    }


    return 0;
}

