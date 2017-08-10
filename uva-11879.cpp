#include <bits/stdc++.h>

using namespace std;

bool isDivisible(char *num, int div);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char number[200];

    while (gets(number)) {
        if (!strcmp(number, "0")) {
            break;
        }

        isDivisible(number, 17) ? printf("1\n") : printf("0\n");
    }

}

bool isDivisible(char *num, int div)
{
    int i, Len, x = 0;

    Len = strlen(num);
    for (i = 0; i < Len; i++) {
        x = x * 10 + num[i] - '0';
        x %= div;
    }

    if (x == 0) {
        return true;
    }

    return false;
}

