#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1000001;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<bool> prime;
    int i, j, sum, Limit, x, xRev;
    char num[10], rev[10];

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
    Limit = sqrt(MAXSIZE);

    /// If any value is prime (i.e. true),
    /// setting the multiples of that value as non-prime (i.e. false)
    /// only for odd numbers
    for (i = 3; i <= Limit; i += 2) {
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

    while (scanf("%d", &x) != EOF) {
        if (prime[x]) {
            sprintf(num, "%d", x);

            Limit = strlen(num);
            for (i = 0, j = Limit - 1; j >= 0; i++, j--) {
                rev[i] = num[j];
            }
            rev[i] = '\0';

            xRev = (int) strtol(rev, NULL, 10);

            if (prime[xRev] && x != xRev) {
                printf("%d is emirp.\n", x);
            }
            else {
                printf("%d is prime.\n", x);
            }
        }
        else {
            printf("%d is not prime.\n", x);
        }
    }

    return 0;
}

