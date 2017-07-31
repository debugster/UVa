#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test, t, i, j, temp, salary[3];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d%d", &salary[0], &salary[1], &salary[2]);

        for (i = 0; i < 2; i++) {
            for (j = i + 1; j < 3; j++) {
                if (salary[i] > salary[j]) {
                    temp = salary[i];
                    salary[i] = salary[j];
                    salary[j] = temp;
                }
            }
        }

        printf("Case %d: %d\n", t, salary[1]);
    }

    return 0;
}
