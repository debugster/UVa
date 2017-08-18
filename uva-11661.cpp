#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char road[2000001];
    int i, Len, D, R, dist, minD;

    while (scanf("%d", &Len)) {
        if (!Len) {
            break;
        }
        scanf("%s", road);

        minD = 3000001;
        D = R = -1;
        for (i = 0; i < Len; i++) {
            if (road[i] == 'Z') {
                minD = 0;
                break;
            }
            else if (road[i] == 'D') {
                D = i;
            }
            else if (road[i] == 'R') {
                R = i;
            }

            if (D != -1 && R != -1) {
                dist = abs(R - D);

                if (dist < minD) {
                    minD = dist;
                }
            }
        }
        printf("%d\n", minD);
    }
    return 0;
}
