#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i;
    double term1, term2, fin, att, total, ct[3];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%lf%lf%lf%lf", &term1, &term2, &fin, &att);
        for (i = 0; i < 3; i++) {
            scanf("%lf", &ct[i]);
        }

        sort(ct, ct + 3);

        total = term1 + term2 + fin + att + (ct[1] + ct[2]) / 2;

        printf("Case %d: ", t);
        if (total >= 90.0) {
            printf("A\n");
        }
        else if (total >= 80.0) {
            printf("B\n");
        }
        else if (total >= 70.0) {
            printf("C\n");
        }
        else if (total >= 60) {
            printf("D\n");
        }
        else {
            printf("F\n");
        }
    }

    return 0;
}

