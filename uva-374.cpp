#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL bigMod(ULL B, ULL P, ULL M);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ULL B, P, M, R;

    while (scanf("%llu%llu%llu", &B, &P, &M) != EOF) {
        R = bigMod(B, P, M);
        printf("%llu\n", R);
    }

    return 0;
}

ULL bigMod(ULL B, ULL P, ULL M)
{
    ULL result;

    if (M == 1) {
        return 0;
    }
    else if (P == 0) {
        return 1;
    }
    else if (P % 2 == 0) {
        result = bigMod(B, P / 2, M);
        return ((result % M) * (result % M)) % M;
    }
    else {
        return ((B % M) * (bigMod(B, P - 1, M) % M)) % M;
    }
}
