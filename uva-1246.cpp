#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 10001;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///     ####################################################    ///
    ///                     Identifying Primes                      ///
    ///     ####################################################    ///

    /// Assuming all the values between 0 and MAXSIZE is prime
    /// Hence initializing all the elements of prime array with 'true'
    vector<bool>prime(MAXSIZE, true);
    int i, j, sum, Limit, x;

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

    /*
    printf("Enter a number not greater than %d : ", MAXSIZE - 1);
    scanf("%d", &x);

    if (x >= 1 && x < MAXSIZE) {
        prime[x] == true ? printf("%d is prime.\n", x) : printf("%d is not prime.\n", x);
    }
    else {
        printf("Input is out of bounds.\n");
    }
    */

    ///     ####################################################    ///
    ///                     Generating Factors                      ///
    ///     ####################################################    ///

    vector<vector<int> >factors(MAXSIZE, vector<int>());
    vector<bool>COUNT(MAXSIZE, false);
    factors[0].push_back(0);
    factors[1].push_back(1);
    for (i = 2; i < MAXSIZE; i++) {
        Limit = sqrt(i);
        if (Limit * Limit == i) {
            for (j = 1; j < Limit; j++) {
                if (i % j == 0) {
                    factors[i].push_back(j);
                    factors[i].push_back(i / j);
                }
            }
            factors[i].push_back(Limit);
        }
        else {
            for (j = 1; j <= Limit; j++) {
                if (i % j == 0) {
                    factors[i].push_back(j);
                    factors[i].push_back(i / j);
                }
            }
        }

        if (prime[factors[i].size()]) {
            COUNT[i] = true;
        }
    }

    /*
    for (i = 0; i < MAXSIZE; i++) {
        printf("%d: ", i);
        for (j = 0; j < factors[i].size(); j++) {
            printf("%d ", factors[i][j]);
        }
        printf("\n");
    }
    */


    ///     ####################################################    ///
    ///                       Main Function                         ///
    ///     ####################################################    ///

    int test, L, H;
    vector<int>ansList;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &L, &H);
        ansList.clear();
        for (i = L; i <= H; i++) {
            if (COUNT[i]) {
                ansList.push_back(i);
            }
        }
        if (ansList.size() == 0) {
            printf("-1\n");
        }
        else {
            for (i = 0; i < ansList.size() - 1; i++) {
                printf("%d ", ansList[i]);
            }
            printf("%d\n", ansList[i]);
        }
    }


    return 0;
}



