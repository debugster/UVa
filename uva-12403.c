#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test;
    unsigned long long k, sum = 0;
    char op[10];

    scanf("%d", &test);
    while (test--) {
        scanf("%s", op);

        switch (op[0]) {
            case 'd':
                scanf("%llu", &k);
                sum += k;
                break;
            case 'r':
                printf("%llu\n", sum);
                break;
        }
    }
    return 0;
}
