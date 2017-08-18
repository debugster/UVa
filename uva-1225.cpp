#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int COUNT[10000][10];
    int digit[10] = {0};
    int i, j, Len, test, n;
    char number[10];

    for (i = 1; i < 10000; i++) {
        sprintf(number, "%d", i);
        Len = strlen(number);
        for (j = 0; j < Len; j++) {
            digit[number[j] - '0']++;
        }

        for (j = 0; j < 10; j++) {
            COUNT[i][j] = digit[j];
        }
    }

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);

        for (i = 0; i < 9; i++) {
            printf("%d ", COUNT[n][i]);
        }
        printf("%d\n", COUNT[n][9]);
    }

    return 0;
}

