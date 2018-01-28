/// RT : 0.200s

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int price[10000];
    int n, m, i, j, a, b, test = 1, dif;
    bool found;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &price[i]);
        }

        scanf("%d", &m);

        sort(price, price + n);

        dif = 1000001;
        for (i = 0; i < n - 1; i++) {
            found = false;
            for (j = i + 1; j < n; j++) {
                if (price[i] + price[j] == m) {
                    found = true;
                    break;
                }
            }
            if (found) {
                if (abs(price[i] - price[j]) < dif) {
                    a = price[i];
                    b = price[j];
                    dif = abs(a - b);
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }

    return 0;
}

