#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int MOD[20];
int currentMod;

void multiply(ULL F[2][2], ULL M[2][2]); /// To calculate F = F * M
void power(ULL F[2][2], int n); /// To calculate F[2][2]^n in O(logn)
int powLogn(int power); /// To calculate 2^power in O(logn)
int findMod(int n, int m);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m, ans;

    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0) {
            printf("0\n");
            continue;
        }

        if (MOD[m] == 0) {
        	MOD[m] = powLogn(m);
        }

        currentMod = MOD[m];
        ans = findMod(n, m);

        printf("%d\n", ans % currentMod);
    }

    return 0;
}

void multiply(ULL F[2][2], ULL M[2][2])
{
	ULL w = (((F[0][0] % currentMod) * (M[0][0] % currentMod)) % currentMod + ((F[0][1] % currentMod) * (M[1][0] % currentMod)) % currentMod) % currentMod;
	ULL x = (((F[0][0] % currentMod) * (M[0][1] % currentMod)) % currentMod + ((F[0][1] % currentMod) * (M[1][1] % currentMod)) % currentMod) % currentMod;
	/// x and y will have the same value
	/// int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	ULL z = (((F[1][0] % currentMod) * (M[0][1] % currentMod)) % currentMod + ((F[1][1] % currentMod) * (M[1][1] % currentMod)) % currentMod) % currentMod;

	F[0][0] = w;
	F[0][1] = F[1][0] = x;
	/// F[1][0] = y;
	F[1][1] = z;
}

void power(ULL F[2][2], int n)
{
	if (n <= 1) {
		return;
	}

	power(F, n / 2);
	multiply(F, F);

	ULL M[2][2] = {
		{1, 1},
		{1, 0}
	};

	if (n % 2 != 0) {
		multiply(F, M);
	}
}

int powLogn(int power)
{
	if (power == 0) {
		return 1;
	}

	int temp = powLogn(power / 2);

	if (power % 2 == 0) {
		return temp * temp;
	}
	else {
		return 2 * temp * temp;
	}
}

int findMod(int n, int m)
{
	ULL fib[2][2] = {
		{1, 1},
		{1, 0}
	};

	power(fib, n);

	return (int) fib[0][1];
}
