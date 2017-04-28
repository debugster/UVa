#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long i, j, a, b, n, m;
    int count, max;

    while (scanf("%llu%llu", &i, &j) != EOF) {

        if (i >= j) {
            a = j;
            b = i;
        }
        else {
            a = i;
            b = j;
        }

        max = 0;
        for (n = a; n <= b; n++) {
            count = 1;

            m = n;
            while (m != 1) {
                if (m % 2 == 0) {
                    m /= 2;
                }
                else {
                    m = 3 * m + 1;
                }
                count++;
            }

            if (count > max) {
                max = count;
            }
        }

        printf("%llu %llu %d\n", i, j, max);
    }

    return 0;
}
