#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char number[20];
    int Len, sum, i;

    while (scanf("%s", number) && strcmp(number, "0") != 0) {

        Len = strlen(number);

        while (Len > 1) {
            sum = 0;
            for (i = 0; i < Len; i++) {
                sum += (int) number[i] - '0';
            }
            sprintf(number, "%d", sum);
            Len = strlen(number);
        }

        printf("%s\n", number);
    }

    return 0;
}
