#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long x, i, sum;

    while (scanf("%llu", &x) != EOF) {
        sum = 0;
        for (i = 1; i <= x; i++) {
            sum += (i * i * i);
        }
        printf("%llu\n", sum);
    }
    return 0;
}
