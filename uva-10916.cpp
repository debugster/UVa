#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /// Memorization from year 1960 to 2160
    /// Rating of particular year 'y' can found from RATING[y - 1960]
    int RATING[201];
    int y, i, range, bit, rate;
    double max, sum;

    for (y = 1960; y <= 2160; y += 10) {

        bit = ((y - 1960) / 10) + 2;
        /// max = pow(2, bit) * log10(2);
        max = 1 << bit;

        sum = 0;
        i = 0;
        while (sum < max) {
            i++;
            /// sum += log10(i);
            sum += log2(i);
        }

        rate = i - 1;

        range = y + 9;
        for (i = y; i <= range; i++) {
            RATING[i - 1960] = rate;
        }
    }

    while (scanf("%d", &y)) {
        if (!y) {
            break;
        }

        printf("%d\n", RATING[y - 1960]);
    }

    return 0;
}

