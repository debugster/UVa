#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;

    while (scanf("%d", &n) && n != 0) {
        printf("%d\n", n / 2);
    }
    return 0;
}
