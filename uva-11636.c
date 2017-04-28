#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t = 1, count, p, n;

    while (scanf("%d", &n) && n >= 0) {
        if (n == 0 || n == 1) {
            p = 0;
        }
        else {
            count = 1;
            p = 0;

            do {
                count *= 2;
                p++;
            } while (count < n);
        }

        printf("Case %d: %d\n", t++, p);
    }
    return 0;
}
