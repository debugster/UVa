#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1000001;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<bool> prime;
    int i, sum, limit, x;

    /// Assuming all the values between 0 and MAXSIZE is prime
    /// Hence initializing all the elements of prime array with 'true'
    for (i = 1; i < MAXSIZE; i++) {
        bool v = true;
        prime.push_back(v);
    }

    /// Setting 0 and 1 as non-prime explicitly
    prime[0] = prime[1] = false;
    /// One and only even prime number
    prime[2] = true;

    /// Marking all even numbers as false
    for (i = 4; i < MAXSIZE; i += 2) {
        prime[i] = false;
    }

    /// Determining the limit of sieve operation
    limit = sqrt(MAXSIZE);

    /// If any value is prime (i.e. true),
    /// setting the multiples of that value as non-prime (i.e. false)
    /// only for odd numbers
    for (i = 3; i <= limit; i += 2) {
        if (prime[i] == true) {
            /// sum = 2 * i;
            sum = i * i; /// Optimized

            while (sum <= MAXSIZE - 1) {
                prime[sum] = false;
                /// sum += i;
                sum += 2 * i; /// Optimized
            }
        }
    }

    int diff;
    while (scanf("%d", &x)) {
        if (x == 0) {
            break;
        }

        for (i = 3; i < MAXSIZE; i++) {
            if (prime[i]) {
                diff = x - i;

                if (prime[diff]) {
                    printf("%d = %d + %d\n", x, i, diff);
                    break;
                }
            }
        }
    }

    return 0;
}
