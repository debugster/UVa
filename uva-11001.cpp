#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    double vTotal, v0, Len, maxLen;
    int maxDisc, i;

    while (scanf("%lf%lf", &vTotal, &v0) && vTotal != 0.0 || v0 != 0) {
        maxLen = 0;
        i = 1;
        maxDisc = 0;
        while ((vTotal / i) >= v0) {
            Len = 0.3 * sqrt((vTotal / i) - v0) * i;

            if (abs(Len - maxLen) < 0.000000000001) {
                maxDisc = 0;
            }
            else if (Len > maxLen) {
                maxDisc = i;
                maxLen = Len;
            }

            i++;
        }

        printf("%d\n", maxDisc);
    }

    return 0;
}
