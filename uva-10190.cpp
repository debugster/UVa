#include <bits/stdc++.h>

using namespace std;

vector<int>series;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m, i;
    bool boring;

    while (scanf("%d%d", &n, &m) != EOF) {

        if (!n || !m || (n == 1 && m == 1) || n < m || (n > 1 && m == 1)) {
            printf("Boring!\n");
            continue;
        }

        series.clear();
        boring = false;

        while (n != 1) {
            if (n % m != 0) {
                boring = true;
                break;
            }

            series.push_back(n);
            n /= m;
        }

        if (boring) {
            printf("Boring!\n");
        }
        else {
            n = series.size();
            for (i = 0; i < n; i++) {
                printf("%d ", series[i]);
            }
            printf("1\n");
        }
    }

    return 0;
}

