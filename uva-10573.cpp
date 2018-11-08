#include <bits/stdc++.h>
#define PI 2*acos(0.0)

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, Len;
    double r, r1, r2, t, area;
    bool spaceFound;
    char input[20];

    scanf("%d", &test);
    getchar();
    while (test--) {
        gets(input);

        /// If input has any white space(s), then there are r1 and r2, otherwise t
        Len = strlen(input);
        spaceFound = false;
        for (i = 0; i < Len; i++) {
            if (input[i] == ' ') {
                spaceFound = true;
                break;
            }
        }

        if (spaceFound) {
            sscanf(input, "%lf%lf", &r1, &r2);
            r = r1 + r2;
        }
        else {
            sscanf(input, "%lf", &t);
            r = t / 2.0;
            r1 = r2 = r / 2.0;
        }

        area = (PI * r * r) - (PI * r1 * r1) - (PI * r2 * r2);
        printf("%.4lf\n", area);
    }

    return 0;
}

