#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t = 1, p, i;
    int stock[13], required[12];

    while (scanf("%d", &p) && p >= 0) {
        stock[0] = p;

        for (i = 1; i < 13; i++) {
            scanf("%d", &stock[i]);
        }

        for (i = 0; i < 12; i++) {
            scanf("%d", &required[i]);
        }

        printf("Case %d:\n", t++);
        for (i = 0; i < 12; i++) {
            if (required[i] <= stock[i]) {
                printf("No problem! :D\n");

                stock[i + 1] += stock[i] - required[i];
            }
            else {
                printf("No problem. :(\n");

                stock[i + 1] += stock[i];
            }
        }
    }
    return 0;
}
