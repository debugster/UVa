#include <bits/stdc++.h>

using namespace std;

int NOD(int x);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, L, H, P, i, D, maxD;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &L, &H);

        maxD = 0;
        for (i = L; i <= H; i++) {
            D = NOD(i);

            //printf("%d - %d\n", i, D);

            if (D > maxD) {
                P = i;
                maxD = D;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, H, P, maxD);
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
