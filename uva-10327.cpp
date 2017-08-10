#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int n, i, temp, minCount, *data;
    bool sorted;

    while (scanf("%d", &n) != EOF) {
        data = (int *) malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }

        minCount = 0;
        while (true) {
            /// Check if already sorted
            sorted = true;
            for (i = 0; i < n - 1; i++) {
                if (data[i] > data[i + 1]) {
                    sorted = false;
                    break;
                }
            }

            if (!sorted) {
                for (i = 0; i < n - 1; i++) {
                    if (data[i] > data[i + 1]) {
                        temp = data[i];
                        data[i] = data[i + 1];
                        data[i + 1] = temp;

                        minCount++;
                    }
                }
            }
            else {
                break;
            }
        }

        printf("Minimum exchange operations : %d\n", minCount);
        free(data);
    }

    return 0;
}
