#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

#define MAX 5000

int data[MAX + 5];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i;
    ULL sum, cost;

    while (scanf("%d", &n) && n != 0) {
        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }

        sort(data, data + n);

        cost = 0;
        for (i = 0; i < n - 1; i++) {
            sum = data[i] + data[i + 1];
            data[i + 1] = sum;
            cost += sum;

            sort(data + i + 1, data + n);
        }

        printf("%llu\n", cost);
    }

    return 0;
}

