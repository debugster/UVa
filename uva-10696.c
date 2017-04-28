#include <stdio.h>

typedef unsigned long long ULL;

ULL f91(ULL n);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ULL n;

    while (scanf("%llu", &n) && n != 0) {
        printf("f91(%llu) = %llu\n", n, f91(n));
    }

    return 0;
}

ULL f91(ULL n)
{
    if (n <= 100) {
        return f91(f91(n + 11));
    }
    else {
        return (n - 10);
    }
}
