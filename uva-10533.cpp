#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1000001;
vector<int> sumPrime(MAXSIZE, 0);

int upperBound(int value);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<bool> prime;
    int test, t1, t2, i, j, digit, n, sum, limit, _count;

    for (i = 2; i < MAXSIZE; i++) {
        bool v = true;
        prime.push_back(v);

        sumPrime[i] = MAXSIZE;
    }

    prime[0] = prime[1] = false;
    sumPrime[0] = sumPrime[1] = MAXSIZE;

    limit = sqrt(MAXSIZE);

    for (i = 2; i <= limit; i++) {
        if (prime[i] == true) {
            sum = 2 * i;

            while (sum <= MAXSIZE - 1) {
                prime[sum] = false;
                sum += i;
            }
        }
    }

    for (i = 2; i < MAXSIZE; i++) {
        if (prime[i] == true) {
            n = i;
            sum = 0;

            do {
                digit = n % 10;
                sum += digit;
                n /= 10;
            } while (n != 0);

            if (prime[sum] == true) {
                sumPrime[i] = i;
            }
        }
    }

    /*for (i = 0; i < MAXSIZE - 1; i++) {
        for (j = i + 1; j < MAXSIZE; j++) {
            if (sumPrime[i] > sumPrime[j]) {
                digit = sumPrime[i];
                sumPrime[i] = sumPrime[j];
                sumPrime[j] = digit;
            }
        }
    }*/

    sort(sumPrime.begin(), sumPrime.end());

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &t1, &t2);

        _count = upperBound(t2) - upperBound(t1 - 1);
        printf("%d\n", _count);
    }

    return 0;
}

int upperBound(int value)
{
    int begI, midI, endI;
    //int SIZE = 30125

    begI = 0;
    endI = 30124;
    midI = (begI + endI) / 2;

    while (begI != endI - 1) {

        if (value < sumPrime[0]) {
            midI = -1;
            break;
        }
        else if (value >= sumPrime[30124]) {
            midI = 30124;
            break;
        }

        if (sumPrime[midI] <= value) {
            begI = midI;
        }
        else {
            endI = midI;
        }

        midI = (begI + endI) / 2;
    }

    return (midI + 1);
}
