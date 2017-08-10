#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned a, b;

    while (scanf("%u%u", &a, &b) != EOF) {
        printf("%u\n", a ^ b);
    }

    return 0;
}
