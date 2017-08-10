#include <bits/stdc++.h>

using namespace std;

vector<char>BIN;

void decToBin(int dec);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, ones;

    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        }

        ones = __builtin_popcount((unsigned) n);
        BIN.clear();
        decToBin(n);

        printf("The parity of ");
        for (i = BIN.size() - 1; i >= 0; i--) {
            printf("%c", BIN[i]);
        }
        printf(" is %d (mod 2).\n", ones);

    }
    return 0;
}

void decToBin(int dec)
{
    int temp;
    char digit;

    do {
        temp = dec % 2;
        digit = temp + '0';

        BIN.push_back(digit);
        dec /= 2;
    } while (dec != 0);
}
