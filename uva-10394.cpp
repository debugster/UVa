#include <bits/stdc++.h>

using namespace std;

/// 100000th TWIN Primes are (18409199, 18409201)
///const int MAXSIZE = 20000001;
const int MAXSIZE = 18409205;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    vector<bool>prime;
    int i, sum, Limit, n, twin[100001];
    bool v;

    /// Assuming all the values between 0 and MAXSIZE is prime
    /// Hence initializing all the elements of prime array with 'true'
    for (i = 1; i < MAXSIZE; i++) {
        v = true;
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

            while (sum < MAXSIZE) {
                prime[sum] = false;
                /// sum += i;
                sum += 2 * i; /// Optimized
            }
        }
    }

    sum = 0;
    for (i = 3; i < MAXSIZE - 2; i++) {
        if (prime[i] && prime[i + 2]) {
            sum++;

            twin[sum] = i;
        }
    }

    while (scanf("%d", &n) != EOF) {
        printf("(%d, %d)\n", twin[n], twin[n] + 2);
    }

    return 0;
}

