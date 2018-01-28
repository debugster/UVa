#include <bits/stdc++.h>

using namespace std;

//unsigned long long UGLY[1501];

int main()
{
    /*
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i;
    unsigned long long j, n;

    UGLY[1] = 1;

    for (i = 2; i <= 1500; i++) {
        j = UGLY[i - 1];
        while (true) {
            j++;
            n = j;

            while(n % 2 == 0) {
                n /= 2;
            }
            while (n % 3 == 0) {
                n /= 3;
            }
            while (n % 5 == 0) {
                n /= 5;
            }

            if (n == 1) {
                UGLY[i] = j;
                printf("UGLY[%d] = %llu\n", i, j);
                break;
            }
        }
    }

    printf("The 1500'th ugly number is %llu.\n", UGLY[1500]);
    */

    printf("The 1500'th ugly number is 859963392.\n");

    return 0;
}

