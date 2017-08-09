/// RT : 0.070s

#include <bits/stdc++.h>

using namespace std;

const int MAX = 64726;
int DATA[MAX];

int NOD(int x);

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

        n = upper_bound(DATA, DATA + MAX, b) - upper_bound(DATA, DATA + MAX, a - 1);

        printf("Case %d: %d\n", t, n);
    }

    return 0;
}

int NOD(int x)
{
    int i, Limit, countD, total = 1;

    Limit = sqrt(x);

    for (i = 2; i <= Limit;) {

        if (i > x) {
            break;
        }

        if (x % i == 0) {
            countD = 1;
            while (x % i == 0) {
                countD++;
                x /= i;
            }
            total *= countD;
        }

        if (i == 2) {
            i++;
        }
        else {
            i += 2;
        }
    }
    if (x > 1) {
        total *= 2;
    }

    return total;
}
