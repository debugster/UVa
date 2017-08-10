#include <bits/stdc++.h>

using namespace std;

vector<char>TER;

void decToTer(long long dec);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long n;
    int i;

    while (scanf("%lld", &n)) {
        if (n < 0) {
            break;
        }

        TER.clear();
        decToTer(n);
        for (i = TER.size() - 1; i >= 0; i--) {
            printf("%c", TER[i]);
        }
        printf("\n");
    }

    return 0;
}

void decToTer(long long dec)
{
    int temp;
    char digit;

    do {
        temp = dec % 3;
        digit = temp + '0';

        TER.push_back(digit);
        dec /= 3;
    } while (dec != 0);
}

