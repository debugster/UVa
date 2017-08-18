#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long number[10001], n, i, j, temp, median;

    i = 0;
    while (scanf("%lld", &n) != EOF) {
        number[i++] = n;

        sort(number, number + i);

        if (i % 2 == 0) {
            median = (number[(i / 2) - 1] + number[i / 2]) / 2;
        }
        else {
            median = number[i / 2];
        }
        printf("%lld\n", median);
    }

    return 0;
}
