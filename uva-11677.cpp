#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int h1, h2, m1, m2, total;

    while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2)) {
        if (!h1 && !m1 && !h2 && !m2) {
            break;
        }

        if (h1 <= h2 && m1 <= m2) {
            total = (h2 - h1) * 60 + (m2 - m1);
        }
        else if (h1 < h2 && m1 > m2) {
            // total = 60 - m1;
            // h1++;
            // total += (h2 - h1) * 60;
            // total += m2;
            total = (60 - m1) + (h2 - h1 - 1) * 60 + m2;
        }
        else {
            // total = 60 - m1;
            // total += (23 - h1) * 60; /// total += (24 - h1 - 1) * 60;
            // total += h2 * 60;
            // total += m2;
            total = 60 - m1 + (23 - h1 + h2) * 60 + m2;
        }
        printf("%d\n", total);
    }

    return 0;
}
