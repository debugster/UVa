#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int testCase = 1, n, i, j, k, amount, perHead, peopleCount;
    int netWorth[10];
    char person[10][20], giver[20], receiver[20];

    while (scanf("%d", &n) != EOF) {

        if (testCase++ > 1) {
            printf("\n");
        }

        for (i = 0; i < n; i++) {
            scanf("%s", person[i]);
            netWorth[i] = 0;
        }

        for (i = 0; i < n; i++) {
            scanf("%s%d%d", giver, &amount, &peopleCount);

            if (peopleCount == 0) {
                continue;
            }
            else {
                perHead = amount / peopleCount;
                amount = perHead * peopleCount;
            }

            for (j = 0; j < n; j++) {
                if (!strcmp(giver, person[j])) {
                    netWorth[j] -= amount;
                    break;
                }
            }

            for (j = 0; j < peopleCount; j++) {
                scanf("%s", receiver);

                /// If giver gives 0 money, then there is no meaning to iterate the following loop
                /// We've to read the receiver list only
                if (amount == 0) {
                    continue;
                }

                for (k = 0; k < n; k++) {
                    if (!strcmp(receiver, person[k])) {
                        netWorth[k] += perHead;
                        break;
                    }
                }
            }
        }

        for (i = 0; i < n; i++) {
            printf("%s %d\n", person[i], netWorth[i]);
        }
    }

    return 0;
}

