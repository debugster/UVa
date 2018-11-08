#include <bits/stdc++.h>
#define MAX 20

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int testCase = 1, n, m, c, i, currentLoad, maxLoad, toggle;
    bool fuseBlown;
    int powerConsumption[MAX + 1];
    bool currentState[MAX + 1];

    while (scanf("%d%d%d", &n, &m, &c), (n && m && c)) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &powerConsumption[i]);
            currentState[i] = false;
        }

        currentLoad = maxLoad = 0;
        fuseBlown = false;
        for (i = 1; i <= m; i++) {
            scanf("%d", &toggle);

            if (currentState[toggle] == false) {
                currentState[toggle] = true;
                currentLoad += powerConsumption[toggle];
            }
            else {
                currentState[toggle] = false;
                currentLoad -= powerConsumption[toggle];
            }

            if (currentLoad > c) {
                fuseBlown = true;
            }

            if (maxLoad < currentLoad) {
                maxLoad = currentLoad;
            }
        }

        printf("Sequence %d\n", testCase++);
        if (fuseBlown) {
            printf("Fuse was blown.\n\n");
        }
        else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maxLoad);
        }
    }

    return 0;
}

