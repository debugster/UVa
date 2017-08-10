#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char name1[30], name2[30], sumStr1[5], sumStr2[5], c;
    int i, sum1, sum2, Len1, Len2;
    double percent;

    while (gets(name1)) {
        gets(name2);

        Len1 = strlen(name1);
        Len2 = strlen(name2);

        sum1 = 0;
        for (i = 0; i < Len1; i++) {
            c = tolower(name1[i]);

            if (c >= 'a' && c <= 'z') {
                sum1 += c - 'a' + 1;
            }
        }

        sum2 = 0;
        for (i = 0; i < Len2; i++) {
            c = tolower(name2[i]);

            if (c >= 'a' && c <= 'z') {
                sum2 += c - 'a' + 1;
            }
        }

        sprintf(sumStr1, "%d", sum1);
        Len1 = strlen(sumStr1);
        do {
            sum1 = 0;
            for (i = 0; i < Len1; i++) {
                sum1 += sumStr1[i] - '0';
            }

            sprintf(sumStr1, "%d", sum1);
            Len1 = strlen(sumStr1);
        } while (Len1 != 1);

        sprintf(sumStr2, "%d", sum2);
        Len2 = strlen(sumStr2);

        do {
            sum2 = 0;
            for (i = 0; i < Len2; i++) {
                sum2 += sumStr2[i] - '0';
            }

            sprintf(sumStr2, "%d", sum2);
            Len2 = strlen(sumStr2);
        } while (Len2 != 1);

        if (sum1 >= sum2) {
            percent = ((double) sum2 / sum1) * 100.0;
        }
        else {
            percent = ((double) sum1 / sum2) * 100.0;
        }
        printf("%.2lf %%\n", percent);
    }
    return 0;
}
