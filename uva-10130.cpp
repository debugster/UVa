#include <bits/stdc++.h>
#define MAX_ITEM 1000
#define MAX_PEOPLE 100
#define MAX_WEIGHT 30

using namespace std;

int n;
int price[MAX_ITEM + 1];
int weight[MAX_ITEM + 1];
int capacity[MAX_PEOPLE + 1];
int DP[MAX_ITEM + 1][MAX_WEIGHT + 1];
int DP2[MAX_WEIGHT + 1]; /// to save maximum profit for a distinct capacity

void init();
int maxProfit(int personNo, int itemNo, int takenWeight);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, j, k, g, total, cap;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &price[i], &weight[i]);
        }

        scanf("%d", &g);
        for (i = 1; i <= g; i++) {
            scanf("%d", &capacity[i]);
        }

        for (i = 0; i <= MAX_WEIGHT; i++) {
            DP2[i] = -1;
        }

        total = 0;
        for (k = 1; k <= g; k++) {

            init();

            cap = capacity[k];
            if (DP2[cap] == -1) {
                DP2[cap] = maxProfit(k, 1, 0);
            }

            total += DP2[cap];
        }

        printf("%d\n", total);
    }

    return 0;
}

void init()
{
    for (int i = 0; i <= MAX_ITEM; i++) {
        for (int j = 0; j <= MAX_WEIGHT; j++) {
            DP[i][j] = 0;
        }
    }
}

int maxProfit(int personNo, int itemNo, int takenWeight)
{
    if (itemNo > n) {
        return 0;
    }
    else if (DP[itemNo][takenWeight] != 0) {
        return DP[itemNo][takenWeight];
    }

    int profit1, profit2;

    if (takenWeight + weight[itemNo] <= capacity[personNo]) {
        profit1 = price[itemNo] + maxProfit(personNo, itemNo + 1, takenWeight + weight[itemNo]);
    }
    else {
        profit1 = 0;
    }

    profit2 = maxProfit(personNo, itemNo + 1, takenWeight);

    return (DP[itemNo][takenWeight] = max(profit1, profit2));
}
