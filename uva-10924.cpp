#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1041;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /// Sieve of Eratosthenes starts here

    vector<bool> prime;
    int i, sum, limit;

    /// Assuming all the values between 0 and MAXSIZE is prime
    /// Hence initializing all the elements of prime array with 'true'
    for (i = 1; i < MAXSIZE; i++) {
        bool v = true;
        prime.push_back(v);
    }

    /// Setting 0 and 1 as non-prime explicitly
    prime[0] = false;

    /// Determining the limit of sieve operation
    limit = sqrt(MAXSIZE);

    /// If any value is prime (i.e. true),
    /// setting the multiples of that value as non-prime(i.e) false
    for (i = 2; i <= limit; i++) {
        if (prime[i] == true) {
            /// sum = 2 * i;
            sum = i * i; /// Optimized

            /// Avoiding Multiplication to find the multiples
            /// Using Addition to reduce the runtime
            while (sum <= MAXSIZE - 1) {
                prime[sum] = false;
                sum += i;
            }
        }
    }

    /// Sieve of Eratosthenes ends here

    char word[21];
    int Len;

    while (gets(word)) {
        Len = strlen(word);

        sum = 0;
        for (i = 0; i < Len; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                sum += (int) word[i] - 'a' + 1;
            }
            else {
                sum += (int) word[i] - 'A' + 27;
            }
        }

        if (prime[sum]) {
            printf("It is a prime word.\n");
        }
        else {
            printf("It is not a prime word.\n");
        }
    }

    return 0;
}



