#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char numStr[20];
    int test, t, sum, Len, i;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%s", numStr);

        printf("Case #%d: %s is ", t, numStr);

        Len = strlen(numStr);

        do {
            sum = 0;
            for (i = 0; i < Len; i++) {
                sum += (numStr[i] - '0') * (numStr[i] - '0');
            }
            sprintf(numStr, "%d", sum);
            Len = strlen(numStr);
        } while (Len != 1);

        if (numStr[0] == '1' || numStr[0] == '7') {
            printf("a Happy number.\n");
        }
        else {
            printf("an Unhappy number.\n");
        }
    }

    return 0;
}
