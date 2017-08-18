#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    unsigned n, root;

    while (scanf("%u", &n)) {
        if (!n) {
            break;
        }

        root = sqrt(n);
        root * root == n ? printf("yes\n") : printf("no\n");
    }

    return 0;
}

