#include <bits/stdc++.h>

using namespace std;

int COMBINATION[101][101];

int buildTable(int n, int r);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m, i, j;

    for (i = 1; i <= 100; i++) {
        for (j = 1; j <= i; j++) {
            COMBINATION[i][j] = buildTable(i, j);
        }
    }

    //printf("Ready\n");

    while (scanf("%d%d", &n, &m)) {
        if (!n) {
            break;
        }

        printf("%d things taken %d at a time is %d exactly.\n", n, m, COMBINATION[n][m]);
    }

    return 0;
}

int buildTable(int n, int r)
{
    if (n == r) {
        return 1;
    }
    else if (r == 1) {
        return n;
    }

    int x, y;
    if (COMBINATION[n - 1][r] == 0) {
        x = buildTable(n - 1, r);
    }
    else {
        x = COMBINATION[n - 1][r];
    }

    if (COMBINATION[n - 1][r - 1] == 0) {
        y = buildTable(n - 1, r - 1);
    }
    else {
        y = COMBINATION[n - 1][r - 1];
    }

    return x + y;
}
