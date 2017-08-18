#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, r, i, m1, m2, dist, dist2;
    vector<int>street;

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &r);

        street.clear();

        for (i = 1; i <= r; i++) {
            scanf("%d", &dist);
            street.push_back(dist);
        }

        sort(street.begin(), street.end());

        if (r % 2 == 1) {
            m1 = r / 2;
            m1 = street[m1];
            dist = 0;
            for (i = 0; i < r; i++) {
                dist += abs(m1 - street[i]);
            }
        }
        else {
            m2 = r / 2;
            m1 = m2 - 1;

            m1 = street[m1];
            m2 = street[m2];

            dist = 0;
            dist2 = 0;
            for (i = 0; i < r; i++) {
                dist += abs(m1 - street[i]);
                dist2 += abs(m2 - street[i]);
            }

            dist = min(dist, dist2);
        }

        printf("%d\n", dist);
    }

    return 0;
}

