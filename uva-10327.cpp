#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int n, i, temp, minCount, swaps, data[1000];
    bool sorted;

    while (scanf("%d", &n) != EOF) {

        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }

        minCount = 0;
        while (true) {

            swaps = 0;
            for (i = 0; i < n - 1; i++) {
                if (data[i] > data[i + 1]) {

                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;

                    swaps++;
                }
            }

            minCount += swaps;
            if (swaps == 0) {
                break;
            }
        }

        printf("Minimum exchange operations : %d\n", minCount);
    }

    return 0;
}
