#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int COUNT[MAX + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, c, root, a, b;

    c = 0;
    for (i = 1; i <= MAX; i++) {
        root = sqrt(i);
        if (root * root == i) {
            c++;
        }
        COUNT[i] = c;
    }

    while (scanf("%d%d", &a, &b)) {
        if (a == 0 && b == 0) {
            break;
        }

        printf("%d\n", COUNT[b] - COUNT[a - 1]);
    }
    return 0;
}
