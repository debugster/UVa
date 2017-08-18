#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, i, j, maxGCD, number[100];
    char dump;

    scanf("%d", &test);
    while (test--) {
        n = 0;

        while (true) {
            scanf("%d", &number[n++]);
            while ((dump = getchar()) == ' ');
            ungetc(dump, stdin);
            if (dump == 10 || dump == -1) {
                break;
            }
        }

        maxGCD = 1;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                maxGCD = max(maxGCD, __gcd(number[i], number[j]));
            }
        }
        printf("%d\n", maxGCD);
    }

    return 0;
}
