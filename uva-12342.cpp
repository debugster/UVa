#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, income, remain;
    double tax;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &income);

        if (income <= 180000) {
            tax = 0;
        }
        else if (income > 180000 && income <= 480000) {
            remain = income - 180000;
            tax = remain * 0.1;
        }
        else if (income > 480000 && income <= 880000) {
            remain = income - 480000;
            /// tax = (300000 * 0.1) + (remain * 0.15);
            tax = 30000 + (remain * 0.15);
        }
        else if (income > 880000 && income <= 1180000) {
            remain = income - 880000;
            /// tax = (300000 * 0.1) + (400000 * 0.15) + (remain * 0.2);
            tax = 30000 + 60000 + (remain * 0.2);
        }
        else {
            remain = income - 1180000;
            /// tax = (300000 * 0.1) + (400000 * 0.15) + (300000 * 0.2) + (remain * 0.25);
            tax = 30000 + 60000 + 60000 + (remain * 0.25);
        }

        if (tax > 0 && tax < 2000) {
            tax = 2000;
        }

        printf("Case %d: %.0lf\n", t, ceil(tax));
    }
    return 0;
}
