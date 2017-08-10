/// RT : 0.090s

#include <bits/stdc++.h>

using namespace std;

#define MAX 500000

vector<bool>PRIME;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, j, n, k, root, Limit, sum, test;
    bool v;

    for (i = 1; i <= MAX; i++) {
        v = true;
        PRIME.push_back(v);
    }

    PRIME[0] = PRIME[1] = false;
    PRIME[2] = true;

    for (i = 4; i <= MAX; i += 2) {
        PRIME[i] = false;
    }

    Limit = sqrt(MAX);

    for (i = 3; i <= Limit; i += 2) {
        if (PRIME[i] == true) {
            /// sum = 2 * i;
            sum = i * i; /// Optimized

            while (sum <= MAX) {
                PRIME[sum] = false;
                /// sum += i;
                sum += 2 * i; /// Optimized
            }
        }
    }

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &k);

        sum = 0;

        if (PRIME[n]) {
            if (k == n) {
                sum = 1;
            }
            else if (k != 1) {
                sum = 1 + n;
            }
        }
        else {
            if (k != 1) {
                Limit = sqrt(n);
                for (i = 1; i <= Limit; i++) {
                    if (n % i == 0) {

                        if (i % k != 0) {
                            sum += i;
                        }

                        if (i * i != n) {
                            j = n / i;
                            if (j % k != 0) {
                                sum += j;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
