/// DP is slower in this case
/// RT : 0.710s

#include <bits/stdc++.h>

using namespace std;

const int MAX = 500000;

vector<vector<int> >DIVISORS;
vector<bool>PRIME;


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    DIVISORS.assign(MAX + 1, vector<int>());

    int i, n, k, root, Limit, sum, test;
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

    DIVISORS[1].push_back(1);

    for (i = 2; i <= MAX; i++) {
        DIVISORS[i].push_back(1);
        DIVISORS[i].push_back(i);

        if (PRIME[i]) {
            continue;
        }

        root = sqrt(i);
        for (n = 2; n <= root; n++) {
            if (i % n == 0) {
                DIVISORS[i].push_back(n);
                if (!(n * n == i)) {
                    DIVISORS[i].push_back(i / n);
                }
            }
        }
    }

    /*
    printf("Ready\n");

    while (scanf("%d", &n) != EOF) {
        printf("%d -> ", n);
        for (i = 0; i < DIVISORS[n].size(); i++) {
            printf("%d ", DIVISORS[n][i]);
        }
        printf("\n");
    }
    */

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &k);

        sum = 0;

        Limit = DIVISORS[n].size();
        for (i = 0; i < Limit; i++) {
            if (DIVISORS[n][i] % k != 0) {
                sum += DIVISORS[n][i];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
