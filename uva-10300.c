#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test;
    unsigned long long f, a, b, c, total;

    while (scanf("%d", &test) != EOF) {
        while (test--) {
            scanf("%llu", &f);
            total = 0;
            while (f--) {
                scanf("%llu%llu%llu", &a, &b, &c);
                if (b != 0) {
                    total += (a * c);
                }
            }
            printf("%llu\n", total);
        }
    }
    return 0;
}
