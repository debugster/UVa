/*UVA-10079*/

#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long n;
    unsigned long long p;
    while (scanf("%lld", &n) && n >= 0) {
        p = (unsigned long long) (n * n + n + 2) / 2;
        printf("%llu\n", p);
    }
    return 0;
}
