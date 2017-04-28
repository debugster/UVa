#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    int n, i, j, sum, s, dif, is_same;
    int *num;

    while (scanf("%d", &n) != EOF) {
        num = (int *) malloc(n * sizeof(int));

        sum = 0;
        is_same = 0;
        for (i = 0, j = 0; i < n; i++) {
            scanf("%d", &num[i]);

            if (i > 0) {
                dif = abs(num[i] - num[i - 1]);
                sum += dif;

                if (dif == 0) {
                    is_same = 1;
                }
            }
        }

        s = (n * (n - 1)) / 2;
        sum == s && is_same == 0 ? printf("Jolly\n") : printf("Not jolly\n");
    }
    return 0;
}
