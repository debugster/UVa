#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    int n, m, i, j, Len, result;
    int digitCount[10];
    char number[10];

    while (scanf("%d%d", &n, &m) != EOF) {
        result = 0;
        for (i = n; i <= m; i++) {
            sprintf(number, "%d", i);
            Len = strlen(number);

            for (j = 0; j < 10; j++) {
                digitCount[j] = 0;
            }

            for (j = 0; j < Len; j++) {
                digitCount[number[j] - '0']++;

                if (digitCount[number[j] - '0'] >= 2) {
                    break;
                }
            }
            if (j == Len) {
                result++;
            }
        }
        printf("%d\n", result);
    }

    return 0;
}
