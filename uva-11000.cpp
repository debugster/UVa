#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

/// number of male bees after N years = number of male bees in (N-1)th year + number of male bees in (N-2)th year + 1
ULL maleBee[51];
ULL femaleBee[51]; /// number of female bees after N years is the (N-1)th Fibonacci number
ULL totalBee[51];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    maleBee[0] = 0, maleBee[1] = 1, maleBee[2] = 2;
    femaleBee[0] = 1, femaleBee[1] = 1, femaleBee[2] = 2;
    totalBee[0] = 1, totalBee[1] = 2, totalBee[2] = 4;

    int N, i;

    for (i = 3; i <= 50; i ++) {
        maleBee[i] = maleBee[i - 1] + maleBee[i - 2] + 1;
        femaleBee[i] = femaleBee[i - 1] + femaleBee[i - 2];
        totalBee[i] = maleBee[i] + femaleBee[i];
    }

    while (scanf("%d", &N) && N != -1) {
        printf("%llu %llu\n", maleBee[N], totalBee[N]);
    }

    return 0;
}

