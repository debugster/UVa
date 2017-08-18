#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, i, duration, mile, juice;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        printf("Case %d: ", t);

        scanf("%d", &n);
        //duration = (int *) malloc(n * sizeof(int));
        mile = juice = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &duration);
            mile += (duration / 30) * 10 + 10;
            juice += (duration / 60) * 15 + 15;
        }

        if (mile == juice) {
            printf("Mile Juice %d\n", mile);
        }
        else if (mile < juice) {
            printf("Mile %d\n", mile);
        }
        else {
            printf("Juice %d\n", juice);
        }
    }
    return 0;
}
