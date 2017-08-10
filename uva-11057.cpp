#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    vector<int>price;
    int n, m, i, j, a, b, test = 1, dif;
    bool found;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &j);
            price.push_back(j);
        }

        sort(price.begin(), price.end());

        scanf("%d", &m);

        dif = 1000001;
        for (i = 0; i < n - 1; i++) {
            found = false;
            for (j = i + 1; j < n; j++) {
                if (price.at(i) + price.at(j) == m) {
                    found = true;
                    break;
                }
            }
            if (found) {
                if (abs(price.at(i) - price.at(j)) < dif) {
                    a = price.at(i);
                    b = price.at(j);
                    dif = abs(price.at(i) - price.at(j));
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);

        price.clear();
    }

    return 0;
}
