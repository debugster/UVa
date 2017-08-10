#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, i, total, *number;
    double avrg, sum;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);

        number = (int *) malloc(n * sizeof(int));
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &number[i]);
            sum += number[i];
        }
        avrg = sum / n;

        total = 0;
        for (i = 0; i < n; i++) {
            sum = (double) number[i];
            if (number[i] > avrg) {
                total++;
            }
        }

        printf("%.3lf%%\n", (total * 100.0)/ n);
    }
    return 0;
}
