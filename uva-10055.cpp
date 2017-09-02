#include <bits/stdc++.h>

using namespace std;

void fastScan(unsigned long long &number);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long x, y;
    char c;

    while ((c = getchar_unlocked()) != EOF) {
        ungetc(c, stdin);

        fastScan(x);
        fastScan(y);

        printf("%llu\n", x >= y ? x - y : y - x);
    }

    return 0;
}

void fastScan(unsigned long long &number)
{
    register unsigned long long c;

    number = 0;

    /// Keep on extracting characters if they are integers
    /// i.e ASCII Value lies from '0'(48) to '9' (57)
    for (c = getchar_unlocked(); (c > 47 && c < 58); c = getchar_unlocked()) {
        number = number * 10 + c - 48;
    }
}
