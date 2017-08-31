#include <bits/stdc++.h>

using namespace std;

unsigned long long DATA[50001];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long x, i, sum;

    DATA[1] = 1;
    for (i = 2; i <= 50000; i++) {
        DATA[i] = DATA[i - 1] + (i * i * i);
    }

    while (scanf("%llu", &x) != EOF) {
        printf("%llu\n", DATA[x]);
    }
    return 0;
}
