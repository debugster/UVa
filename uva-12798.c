#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m, i, j, count, zero, data;

    while (scanf("%d%d", &n, &m) != EOF) {

        count = 0;

        for (i = 1; i <= n; i++) {
            zero = 0;
            for (j = 1; j <= m; j++) {
                scanf("%d", &data);

                if (data == 0) {
                    zero++;
                }
            }
            if (zero == 0) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
