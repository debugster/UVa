#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 65001;

unsigned bigMod(unsigned B, unsigned P, unsigned M);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<bool>prime;
    int i, sum, Limit, mod;
    unsigned a, n;
    bool CARMICHAEL[MAXSIZE];

    /// Assuming all the values between 0 and MAXSIZE is prime
    /// Hence initializing all the elements of prime array with 'true'
    for (i = 0; i < MAXSIZE; i++) {
        prime.push_back(true);
        CARMICHAEL[i] = false;
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

    for (n = 4; n < MAXSIZE; n++) {
        if (!prime[n]) {
            CARMICHAEL[n] = true;
            for (a = 2; a < n; a++) {
                if (bigMod(a, n, n) != a) {
                    CARMICHAEL[n] = false;
                    break;
                }
            }
        }
    }

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        CARMICHAEL[n] ? printf("The number %u is a Carmichael number.\n", n) : printf("%u is normal.\n", n);
    }

    return 0;
}

unsigned bigMod(unsigned B, unsigned P, unsigned M)
{
    if (M == 1) {
        return 0;
    }
    else if (P == 0) {
        return 1;
    }
    else if (P % 2 == 0) {
        unsigned result = bigMod(B, P / 2, M);
        return ((result % M) * (result % M)) % M;
    }
    else {
        return ((B % M) * (bigMod(B, P - 1, M) % M)) % M;
    }
}
