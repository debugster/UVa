#include <bits/stdc++.h>

using namespace std;

const int LastLimit = 1299709;
const int MAXSIZE = 1300000;

int LENGTH[LastLimit + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<bool>prime(MAXSIZE, true);
    int i, j, sum, Limit, a, b, Len;

    /// Setting 0 and 1 as non-prime explicitly
    prime[0] = prime[1] = false;
    /// One and only even prime number
    prime[2] = true;

    /// Marking all even numbers as false
    for (i = 4; i < MAXSIZE; i += 2) {
        prime[i] = false;
    }

    /// Determining the limit of sieve operation
    Limit = sqrt(MAXSIZE);

    /// If any value is prime (i.e. true),
    /// setting the multiples of that value as non-prime (i.e. false)
    /// only for odd numbers
    for (i = 3; i <= Limit; i += 2) {
        if (prime[i] == true) {
            /// sum = 2 * i;
            sum = i * i; /// Optimized

            while (sum < MAXSIZE) {
                prime[sum] = false;
                /// sum += i;
                sum += 2 * i; /// Optimized
            }
        }
    }

    for (i = 2; i <= LastLimit; ) {
        if (prime[i]) {
            a = i;
            b = i + 1;
            while (!prime[b]) {
                b++;
            }

            Len = b - a;
            for (j = a + 1; j < b; j++) {
                LENGTH[j] = Len;
            }
            i = b;
        }
    }

    while (scanf("%d", &a)) {
        if (!a) {
            break;
        }

        printf("%d\n", LENGTH[a]);
    }

    return 0;
}
