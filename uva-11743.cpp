#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, i, j;
    int sumDouble, sumSingle, sumTotal, temp, Len;
    char cc[50];

    scanf("%d", &test);
    getchar();
    while (test--) {

        sumDouble = sumSingle = 0;

        gets(cc);
        /// Len = strlen(cc);
        Len = 19;

        for (i = 0, j = 0; i < Len; i++) {
            if (cc[i] == ' ') {
                continue;
            }

            n = cc[i] - '0';
            j++;

            if (j % 2 == 0) {
                sumSingle += n;
            }
            else {
                temp = n * 2;
                sumDouble += (temp / 10) + (temp % 10);
            }
        }

        sumTotal = sumSingle + sumDouble;

        if (sumTotal % 10 == 0) {
            printf("Valid\n");
        }
        else {
            printf("Invalid\n");
        }
    }

    return 0;
}

