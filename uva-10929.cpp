#include <bits/stdc++.h>

using namespace std;

char number[1001];
int Length;

bool divisible_by_11();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while (gets(number)) {

        if (!strcmp(number, "0")) {
            break;
        }

        Length = strlen(number);

        if (divisible_by_11()) {
            printf("%s is a multiple of 11.\n", number);
        }
        else {
            printf("%s is not a multiple of 11.\n", number);
        }
    }
    return 0;
}

bool divisible_by_11()
{
    int odd_sum = 0, even_sum = 0, diff, i;

    for (i = 0; i < Length; i++) {
        if ((i + 1) % 2 == 1) {
            odd_sum += (int) number[i] - 48;
        }
        else {
            even_sum += (int) number[i] - 48;
        }
    }

    diff = abs(odd_sum - even_sum);

    if (diff % 11 == 0) {
        return true;
    }

    return false;
}
