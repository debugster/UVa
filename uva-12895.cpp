#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, Len;
    ULL sum;
    char number[12], arm[20], dump;

    scanf("%d", &test);
    while (test--) {
        scanf("%s", number);
        Len = strlen(number);

        sum = 0;
        for (i = 0; i < Len; i++) {
            sum += (ULL) pow(number[i] - '0', Len);
        }

        sprintf(arm, "%llu", sum);

        if (!strcmp(number, arm)) {
            printf("Armstrong\n");
        }
        else {
            printf("Not Armstrong\n");
        }
    }
    return 0;
}
