#include <bits/stdc++.h>
#define MAX 2000005

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int N, B, H, W, p, a, i, j, cost, minCost;
    bool found, enoughRoom;

    while (scanf("%d%d%d%d", &N, &B, &H, &W) != EOF) {

        minCost = MAX;
        found = false;

        for (i = 1; i <= H; i++) {
            scanf("%d", &p);

            enoughRoom = false;
            for (j = 1; j <= W; j++) {
                scanf("%d", &a);
                if (!enoughRoom && a >= N) {
                    enoughRoom = true;
                }
            }

            if (enoughRoom) {
                cost = N * p;

                if (cost < minCost) {
                    minCost = cost;

                    if (minCost <= B) {
                        found = true;
                    }
                }
            }
        }

        if (found) {
            printf("%d\n", minCost);
        }
        else {
            printf("stay home\n");
        }
    }

    return 0;
}

