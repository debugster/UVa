#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int k, i, data[13], test = 1;

    while (scanf("%d", &k) && k != 0) {
        for (i = 1; i <= k; i++) {
            scanf("%d", &data[i]);
        }

        if (test != 1) {
            printf("\n");
        }
        test++;

        int a, b, c, d, e, f;

        for (a = 1; a <= k - 5; a++) {
            for (b = a + 1; b <= k - 4; b++) {
                for (c = b + 1; c <= k - 3; c++) {
                    for (d = c + 1; d <= k - 2; d++) {
                        for (e = d + 1; e <= k - 1; e++) {
                            for (f = e + 1; f <= k; f++) {
                                printf("%d %d %d %d %d %d\n", data[a],data[b],data[c],data[d],data[e],data[f]);
                            }
                        }
                    }
                }
            }
        }

    }
    return 0;
}
