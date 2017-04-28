#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long a, b;
    int test;

    scanf("%d", &test);
    while (test--) {
        scanf("%lld%lld", &a, &b);

        if (a == b) {
            printf("=\n");
        }
        else if (a > b) {
            printf(">\n");
        }
        else {
            printf("<\n");
        }
    }
    return 0;
}
