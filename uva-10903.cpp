/// uHunt Rank : 24
/// Time : 0.100

#include <bits/stdc++.h>

using namespace std;

struct
{
    int win;
    int lose;
} player[101];

char choiceList[3][10] = {"rock", "scissors", "paper"};
int resultList[3][3] = { {0, 1, 2},
                        {2, 0, 1},
                        {1, 2, 0} };

int getChoice(char *s);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, k, i, p1, p2, choice1, choice2, result, total, testCaseCount = 1;
    char input1[10], input2[10];

    while (scanf("%d", &n) && n != 0) {

        for (i = 1; i <= 100; i++) {
            player[i].win = player[i].lose = 0;
        }

        scanf("%d", &k);
        k = k * n * (n - 1) / 2;

        for (i = 1; i <= k; i++) {
            scanf("%d %s %d %s", &p1, input1, &p2, input2);

            choice1 = getChoice(input1);
            choice2 = getChoice(input2);

            result = resultList[choice1][choice2];

            switch (result) {
                case 1:
                    player[p1].win++;
                    player[p2].lose++;
                    break;

                case 2:
                    player[p1].lose++;
                    player[p2].win++;
                    break;
            }
        }

        if (testCaseCount != 1) {
            printf("\n");
        }
        testCaseCount++;

        for (i = 1; i <= n; i++) {
            total = player[i].win + player[i].lose;

            if (total != 0) {
                printf("%.3lf\n", (double) player[i].win / total);
            }
            else {
                printf("-\n");
            }
        }
    }
}

int getChoice(char *s)
{
    int c, i;

    /*for (i = 0; i < 3; i++) {
        if (strcmp(s, choiceList[i]) == 0) {
            c = i;
            break;
        }
    }*/

    /// Following switch statement works faster than preceding for-loop
    switch (s[0]) {
        case 'r':
            c = 0;
            break;
        case 's':
            c = 1;
            break;
        case 'p':
            c = 2;
            break;
    }

    return c;
}
