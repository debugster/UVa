#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL MOD = 1000000009;

void multiply(ULL F[3][3]); /// To calculate F = F * F
void multiply(ULL F[3][3], ULL M[3][3]); /// To calculate F = F * M
void power(ULL F[3][3], ULL n); /// To calculate F[2][2]^n in O(logn)
ULL findMod(ULL n);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ULL n, ans;

    while (scanf("%llu", &n) && n != 0) {

        ans = findMod(n);

        printf("%llu\n", ans % MOD);
    }

    return 0;
}

void multiply(ULL F[3][3])
{
    int i, j, k;
    ULL sum, temp, F_copy[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum = 0;
            for (k = 0; k < 3; k++) {
                temp = ((F[i][k] % MOD) * (F[k][j] % MOD)) % MOD;
                sum = ((sum % MOD) + (temp % MOD)) % MOD;
            }
            F_copy[i][j] = sum;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            F[i][j] = F_copy[i][j];
        }
    }
}

void multiply(ULL F[3][3], ULL M[3][3])
{
	ULL x = (((F[0][0] % MOD) * (M[0][0] % MOD)) % MOD + ((F[0][1] % MOD) * (M[1][0] % MOD)) % MOD + ((F[0][2] % MOD) * (M[2][0] % MOD)) % MOD) % MOD;
	ULL y = (((F[0][0] % MOD) * (M[0][1] % MOD)) % MOD + ((F[0][1] % MOD) * (M[1][1] % MOD)) % MOD + ((F[0][2] % MOD) * (M[2][1] % MOD)) % MOD) % MOD;
	ULL z = (((F[0][0] % MOD) * (M[0][2] % MOD)) % MOD + ((F[0][1] % MOD) * (M[1][2] % MOD)) % MOD + ((F[0][2] % MOD) * (M[2][2] % MOD)) % MOD) % MOD;

    F[2][0] = F[1][0];
    F[2][1] = F[1][1];
    F[2][2] = F[1][2];

    F[1][0] = F[0][0];
    F[1][1] = F[0][1];
    F[1][2] = F[0][2];

    F[0][0] = x;
    F[0][1] = y;
    F[0][2] = z;
}

void power(ULL F[3][3], ULL n)
{
	if (n <= 1) {
		return;
	}

	power(F, n / 2);
	multiply(F);

	ULL M[3][3] = {
		{1, 1, 1},
		{1, 0, 0},
		{0, 1, 0}
	};

	if (n % 2 != 0) {
		multiply(F, M);
	}
}

ULL findMod(ULL n)
{
	ULL fib[3][3] = {
		{1, 1, 1},
		{1, 0, 0},
		{0, 1, 0}
	};

	power(fib, n);

	return fib[1][1];
}
