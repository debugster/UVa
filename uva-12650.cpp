#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, r, i, x;
    bool ID[10001];

    while (scanf("%d%d", &n, &r) != EOF) {

        if (n != r) {
            for (i = 1; i <= n; i++) {
                ID[i] = true;
            }
        }

        for (i = 1; i <= r; i++) {
            scanf("%d", &x);
            ID[x] = false;
        }

        if (n == r) {
            printf("*\n");
        }
        else {
            for (i = 1; i <= n; i++) {
                if (ID[i]) {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
