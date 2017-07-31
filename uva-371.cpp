#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long i, j, a, b, n, m, number;
    int count, max;

    while (scanf("%llu%llu", &i, &j) != EOF) {

        if (i == 0 && j == 0) {
            break;
        }

        if (i >= j) {
            a = j;
            b = i;
        }
        else {
            a = i;
            b = j;
        }

        max = 0;
        for (n = a; n <= b; n++) {
            count = 1;

            m = n;
            do {
                if (m % 2 == 0) {
                    m /= 2;
                }
                else {
                    m = 3 * m + 1;
                }
                count++;
            } while (m != 1);

            if (count > max) {
                max = count;
                number = n;
            }
        }

        //printf("%llu %llu %d\n", a, b, max);
        printf("Between %llu and %llu, %llu generates the longest sequence of %d values.\n", a, b, number, max - 1);
    }

    return 0;
}
