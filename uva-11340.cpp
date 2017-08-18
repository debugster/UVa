#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    double costTable[256], totalCost, value;
    int test, k, n, i, j;
    char c[10], dump, Line[11000];

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &k);
        dump = getchar();

        for (i = 0; i < 256; i++) {
            costTable[i] = 0;
        }

        for (i = 1; i <= k; i++) {
            scanf("%s%lf", c, &value);
            //dump = getchar();
            costTable[c[0]] = value;
        }

        scanf("%d", &n);
        dump = getchar();
        totalCost = 0;
        for (i = 1; i <= n; i++) {
            gets(Line);
            k = strlen(Line);
            for (j = 0; j < k; j++) {
                totalCost += costTable[Line[j]];
            }
        }

        totalCost /= 100;
        printf("%.2lf$\n", totalCost);
    }
    return 0;
}
