#include <bits/stdc++.h>

using namespace std;

bool LeapYear[3001];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, d, m, y, qy, total;

    for (i = 1848; i <= 3000; i += 4) {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
            LeapYear[i] = true;
        }
    }

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d%d%d", &d, &m, &y, &qy);

        total = 0;
        if (d == 29 && m == 2) {
            for (i = y + 4; i <= qy; i += 4) {
                if (LeapYear[i]) {
                    total++;
                }
            }
        }
        else {
            total = qy - y;
        }

        printf("Case %d: %d\n", t, total);
    }

    return 0;
}

