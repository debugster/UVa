#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test;
    unsigned long long sum, diff, x, y;

    scanf("%d", &test);
    while (test--) {
        scanf("%llu%llu", &sum, &diff);

        x = sum + diff;
        if (sum < diff || x & 1) {
            printf("impossible\n");
        }
        else {
            y = x / 2;
            printf("%llu %llu\n", y, sum - y);
        }
    }

    return 0;
}

