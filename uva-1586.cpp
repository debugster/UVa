#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, j, Len, n;
    char mole[100], dump;
    double total;

    scanf("%d", &test);
    while (test--) {
        /// This program got TLE for using gets() :o
        scanf("%s", mole);
        Len = strlen(mole);

        total = 0;
        for (i = 0; i < Len;) {
            if (mole[i] >= 'A' && mole[i] <= 'Z') {
                dump = mole[i];
                if (mole[i + 1] >= 'A' && mole[i + 1] <= 'Z' || mole[i + 1] == '\0') {
                    n = 1;
                    i++;
                }
                /// Preceding character(s) is a digit or number
                else {
                    /// Double digit
                    if (mole[i + 2] >= '0' && mole[i + 2] <= '9') {
                        n = (mole[i + 1] - '0') * 10 + (mole[i + 2] - '0');
                        i += 3;
                    }
                    /// Single digit
                    else {
                        n = mole[i + 1] - '0';
                        i += 2;
                    }
                }
            }

            switch (dump) {
                    case 'C':
                        total += (n * 12.01);
                        break;

                    case 'H':
                        total += (n * 1.008);
                        break;

                    case 'O':
                        total += (n * 16.0);
                        break;

                    case 'N':
                        total += (n * 14.01);
                        break;
            }
            if (i >= Len) break;
        }
        printf("%.3lf\n", total);
    }
    return 0;
}
