#include <bits/stdc++.h>

using namespace std;

const int MAX = 64726;
vector<int>DATA(MAX, 0);

int NOD(int x);
int upperBound(int value);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, n, test, t, a, b;

    DATA[0] = 1;
    for (i = 1; i < MAX; i++) {
        DATA[i] = DATA[i - 1] + NOD(DATA[i - 1]);
    }

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d", &a, &b);

        n = upperBound(b) - upperBound(a - 1);

        printf("Case %d: %d\n", t, n);
    }

    return 0;
}

int NOD(int x)
{
    int n, limit, total = 2;

    if (x == 1) {
        total = 1;
        return total;
    }

    limit = sqrt(x);
    for (n = 2; n <= limit; n++) {
        if (x % n == 0 && x / n == n) {
            total++;
        }
        else if (x % n == 0) {
            total += 2;
        }
    }
    return total;
}

int upperBound(int value)
{
    int begI, midI, endI;

    begI = 0;
    endI = MAX - 1;
    midI = (begI + endI) / 2;

    while (begI != endI - 1) {

        if (value < DATA[0]) {
            midI = -1;
            break;
        }
        else if (value >= DATA[MAX - 1]) {
            midI = MAX - 1;
            break;
        }

        if (DATA[midI] <= value) {
            begI = midI;
        }
        else {
            endI = midI;
        }

        midI = (begI + endI) / 2;
    }

    return (midI + 1);
}
