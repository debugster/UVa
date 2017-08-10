/// RT : 0.520s

#include <bits/stdc++.h>

using namespace std;

bool isDivisible(char *num, int div);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    char number[1000000];

    while (scanf("%d", &n) != EOF) {
        strcpy(number, "1");
        while (isDivisible(number, n) == false) {
            strcat(number, "1");
        }
        printf("%d\n", strlen(number));
    }
    return 0;
}

bool isDivisible(char *num, int div)
{
    int x, i, Len;

    Len = strlen(num);
    x = 0;

    for (i = 0; i < Len; i++) {
        x = x * 10 + num[i] - '0';
        x %= div;
    }

    if (x == 0) {
        return true;
    }
    return false;
}
