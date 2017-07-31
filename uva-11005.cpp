#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int digitCost[36];
int totalCost[37];
int minCost;
vector<int>minCostLocation;

void decimalToAnyCost(ULL dec);

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);
    int test, t, i, j, b, q, numberSize, cost, index;

    ULL decimal;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        for (i = 0; i < 36; i++) {
            scanf("%d", &digitCost[i]);
        }

        printf("Case %d:\n", t);

        scanf("%d", &q);
        for (j = 1; j <= q; j++) {
            scanf("%llu", &decimal);

            decimalToAnyCost(decimal);

            printf("Cheapest base(s) for number %llu: ", decimal);

            numberSize = minCostLocation.size() - 1;
            for (i = 0; i <= numberSize; i++) {
                printf("%d", minCostLocation[i]);

                if (i != numberSize) {
                    printf(" ");
                }
            }
            printf("\n");
            minCostLocation.clear();
            //for (i = 2; i <= 36; i++) {
            //    printf("%d ", totalCost[i]);
            //}
        }
        if (t != test) {
            printf("\n");
        }
    }

    return 0;
}

void decimalToAnyCost(ULL dec)
{
    int temp, b, cost;
    char digit;
    ULL decTemp;

    for (b = 2; b <= 36; b++) {
        cost = 0;
        decTemp = dec;
        do {
            temp = decTemp % b;

            cost += digitCost[temp];
            decTemp /= b;
        } while (decTemp != 0);

        totalCost[b] = cost;

        if (b == 2) {
            minCost = cost;
            minCostLocation.push_back(b);
        }
        else {

            if (cost == minCost) {
                minCostLocation.push_back(b);
            }

            if (cost < minCost) {
                minCost = cost;
                minCostLocation.clear();
                minCostLocation.push_back(b);
            }
        }
    }
}

