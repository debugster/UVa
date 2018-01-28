#include <bits/stdc++.h>
#define MAX_COIN 5
#define MAX_AMOUNT 7489

using namespace std;

int coin[] = {0, 1, 5, 10, 25, 50};
int DP[MAX_COIN + 1][MAX_AMOUNT + 1];
int DP2[MAX_AMOUNT + 1];
int makeAmount;

int makeChange(int coinNo, int amountMade); /// returns in how many ways makeAmount can be made

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    memset(DP, -1, sizeof(DP));
    while (scanf("%d", &makeAmount) != EOF) {
        if (DP2[makeAmount] == 0) {
            DP2[makeAmount] = makeChange(1, makeAmount);
        }

        printf("%d\n", DP2[makeAmount]);
    }

    return 0;
}

int makeChange(int coinNo, int amountMade)
{
    if (amountMade == 0) {
        return 1;
    }
    else if (coinNo > MAX_COIN) {
        return 0;
    }

    if (DP[coinNo][amountMade] != -1) {
        return DP[coinNo][amountMade];
    }

    int count1 = 0, count2 = 0;

    if (amountMade - coin[coinNo] >= 0) {
        count1 = makeChange(coinNo, amountMade - coin[coinNo]);
    }
    count2 = makeChange(coinNo + 1, amountMade);

    return (DP[coinNo][amountMade] = (count1 + count2));
}
