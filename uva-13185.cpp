#include <bits/stdc++.h>

using namespace std;

#define deficient 1
#define perfect 2
#define abundant 3

int DPA[1001];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, sum, Limit, i, q;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);

        if (DPA[n] == 0) {
            sum = 1;
            Limit = sqrt(n);
            for (i = 2; i <= Limit; i++) {
                if (n % i == 0) {
                    q = n / i;

                    if (q == i) {
                        sum = sum + i;
                    }
                    else {
                        sum = sum + i + q;
                    }
                }
            }

            if (sum < n) {
                DPA[n] = deficient;
            }
            else if (sum == n) {
                DPA[n] = perfect;
            }
            else {
                DPA[n] = abundant;
            }
        }

        if (DPA[n] == deficient) {
            printf("deficient\n");
        }
        else if (DPA[n] == perfect) {
            printf("perfect\n");
        }
        else {
            printf("abundant\n");
        }
    }

    return 0;
}

