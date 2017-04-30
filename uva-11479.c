#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t;
    long long a, b, c;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%lld%lld%lld", &a, &b, &c);

        printf("Case %d: ", t);

        if (a > 0 && b > 0 && c > 0) {
            if (a + b > c && b + c > a && c + a > b) {
                if (a == b && b == c) {
                    printf("Equilateral\n");
                }
                else if (a == b || b == c || c == a) {
                    printf("Isosceles\n");
                }
                else {
                    printf("Scalene\n");
                }
            }
            else {
                printf("Invalid\n");
            }
        }
        else {
            printf("Invalid\n");
        }
    }
    return 0;
}
