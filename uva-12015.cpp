#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, max, relevence[10];
    char site[10][102];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {

        max = 0;
        for (i = 0; i < 10; i++) {
            scanf("%s %d", site[i], &relevence[i]);
            if (relevence[i] > max) {
                max = relevence[i];
            }
        }

        printf("Case #%d:\n", t);

        for (i = 0; i < 10; i++) {
            if (relevence[i] == max) {
                printf("%s\n", site[i]);
            }
        }
    }
    return 0;
}
