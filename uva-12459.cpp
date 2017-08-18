#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned long long FIBONACCI[81];
    int n, i;

    FIBONACCI[0] = 1;
    FIBONACCI[1] = 1;
    for (i = 2; i <= 80; i++) {
        FIBONACCI[i] = FIBONACCI[i - 1] + FIBONACCI[i - 2];
    }

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        printf("%llu\n", FIBONACCI[n]);
    }
    return 0;
}
