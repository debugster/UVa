#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, a, b, c;

    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &c);

        if (a + b > c && b + c > a && c + a > b) {
            printf("OK\n");
        }
        else {
            printf("Wrong!!\n");
        }
    }
    return 0;
}
