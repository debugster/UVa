/// RT : 0.570

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int factorSize;
    int n, i, limit;
    vector<int>factors;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        if (n == -1) {
            printf("-1 = -1 x \n");
            continue;
        }
        else if (n == 1) {
            printf("1 = \n");
            continue;
        }

        factors.clear();

        printf("%d = ", n);

        if (n < 0) {
            printf("-1 x ");
            n *= -1;
        }

        limit = sqrt(n);
        for (i = 2; i <= limit; ) {
            if (i > n) {
                break;
            }

            if (n % i == 0) {
                while (n % i == 0) {
                    factors.push_back(i);
                    n /= i;
                }
            }

            if (i == 2) {
                i++;
            }
            else {
                i += 2;
            }
        }
        if (n != 1) {
            factors.push_back(n);
        }

        /*
        vector<long long>::iterator p = factors.begin();
        i = 1;
        while (p != factors.end()) {
            if (i != factors.size()) {
                printf("%lld x ", *p);
            }
            else {
                printf("%lld", *p);
            }
            p++;
            i++;
        }
        */

        factorSize = factors.size();
        for (i = 0; i < factorSize - 1; i++) {
            printf("%d x ", factors[i]);
        }
        printf("%d\n", factors[i]);
    }
    return 0;
}
