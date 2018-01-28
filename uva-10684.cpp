#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int data[10001];
    int n, i, sum, max;

    while (scanf("%d", &n) && n != 0) {
        max = 0;
        sum = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &data[i]);

            sum += data[i];

            if (sum < 0) {
                sum = 0;
            }

            if (max < sum) {
                max = sum;
            }
        }
        if (max > 0) {
            printf("The maximum winning streak is %d.\n", max);
        }
        else {
            printf("Losing streak.\n");
        }
    }

    return 0;
}
