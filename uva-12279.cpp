#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, test = 1, i, m, supposedTreat, givenTreat;

    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }

        supposedTreat = givenTreat = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &m);
            if (m == 0) {
                givenTreat++;
            }
            else {
                supposedTreat++;
            }
        }
        printf("Case %d: %d\n", test++, supposedTreat - givenTreat);
    }
    return 0;
}
