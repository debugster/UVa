#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, sum, move, av, count = 1;
    int *num;

    while (scanf("%d", &n) && n != 0) {
        num = (int *) malloc(n * sizeof (int));

        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            sum += num[i];
        }

        av = sum / n;

        move = 0;
        for (i = 0; i < n; i++) {
            if (num[i] > av) {
                move += (num[i] - av);
            }
        }

        printf("Set #%d\n", count++);
        printf("The minimum number of moves is %d.\n\n", move);
    }
    return 0;
}
