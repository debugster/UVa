#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, r;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        r = (((n * 63) + 7492) * 5) - 498;
        r /= 10;
        r %= 10;
        printf("%d\n", abs(r));
    }
    return 0;
}
