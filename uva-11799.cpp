#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int test, t, n, i, speed, maxValue;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);

        maxValue = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &speed);

            if (speed > maxValue) {
                maxValue = speed;
            }
        }
        printf("Case %d: %d\n", t, maxValue);
    }
    return 0;
}
