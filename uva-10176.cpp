#include <bits/stdc++.h>
#define B 2
#define M 131071

using namespace std;

typedef unsigned long long ULL;

ULL bigMod(ULL P); /// returns B^P % M

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char s[10005];
    string number;
    int Len, i, j;
    ULL sum;

    while (gets(s)) {
        Len = strlen(s);

        if (s[Len - 1] == '#') {
            s[Len - 1] = '\0';
            number += s;

            Len = number.size();
            sum = 0;
            for (i = 0, j = Len - 1; i < Len; i++, j--) {
                if (number[i] == '1') {
                    sum += bigMod(j);
                }
            }

            if (sum % M == 0) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }

            number.clear();
        }
        else {
            number += s;
        }
    }

    return 0;
}

ULL bigMod(ULL P)
{
    if (P == 0) {
        return 1 % M;
    }
    else if (P % 2 == 0) {
        /// ULL result = bigMod(B, P / 2, M);
        /// return ((result % M) * (result % M)) % M;
        ULL result = bigMod(P / 2) % M;
        return (result * result) % M;
    }
    else {
        return ((B % M) * (bigMod(P - 1) % M)) % M;
    }
}
