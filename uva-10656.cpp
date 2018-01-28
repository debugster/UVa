#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, number, c;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        c = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &number);
            if (number > 0) {
                c++;
                if (c != 1) {
                    printf(" ");
                }
                printf("%d", number);
            }
        }
        if (c == 0) {
            printf("0");
        }

        printf("\n");
    }

    return 0;
}

