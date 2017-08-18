#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    unsigned long long i, fact[14];

    fact[0] = 1;

    for (i = 1; i < 14; i++) {
        fact[i] = i * fact[i - 1];
    }

    while (scanf("%d", &n) != EOF) {
        if (n < 8) {
            if (n < 0 && !(n % 2 == 0)) {
                printf("Overflow!\n");
            }
            else {
                printf("Underflow!\n");
            }
        }
        else if (n > 13) {
            printf("Overflow!\n");
        }
        else {
            printf("%llu\n", fact[n]);
        }
    }
    return 0;
}
