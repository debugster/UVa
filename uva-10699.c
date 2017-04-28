#include <stdio.h>
#include <math.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int prime[80000] = {0}, i, j, k, limit, is_prime;
    int n, count;

    for (i = 2, j = 0; i <= 1000000; i++) {
        is_prime = 1;
        limit = sqrt(i);

        for (k = 2; k <= limit; k++) {
            if (i % k == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime == 1) {
            prime[j++] = i;
        }
    }

    while (scanf("%d", &n) && n != 0) {
        count = 0;
        for (i = 0; i < j; i++) {
            if (n % prime[i] == 0) {
                count++;
            }
        }

        printf("%d : %d\n", n, count);
    }

    return 0;
}
