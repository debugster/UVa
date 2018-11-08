#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

char number[MAX + 5];
int cumSum[MAX + 5];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, j, k, Len, sum, testCase = 1;
    bool isSame;

    while (scanf("%s", number) == 1) {

        printf("Case %d:\n", testCase++);

        Len = strlen(number);
        cumSum[0] = number[0] - '0';
        for (i = 1; i < Len; i++) {
            cumSum[i] = cumSum[i - 1] + (number[i] - '0');
        }

        scanf("%d", &n);
        for (k = 1; k <= n; k++) {
            scanf("%d%d", &i, &j);

            if (i > j) {
                swap(i, j);
            }


            if (i != 0) {
                sum = cumSum[j] - cumSum[i - 1];
            }
            else {
                sum = cumSum[j];
            }

            if (sum == 0 || sum == j - i + 1) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }

    return 0;
}

