#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int mod;
int data[MAX + 5];

bool compare(int x, int y)
{
    int modX = x % mod;
    int modY = y % mod;

    if (modX < modY) {
        return true;
    }
    else if (modX > modY) {
        return false;
    }
    else {
        int xMOD = x % 2;
        int yMOD = y % 2;

        if ((xMOD == 1 || xMOD == -1) && yMOD == 0) {
            return true;
        }
        if (x % 2 == 0 && (yMOD == 1 || yMOD == -1)) {
            return false;
        }
        if ((xMOD == 1 || xMOD == -1) && (yMOD == 1 || yMOD == -1)) {
            return x > y;
        }
        if (xMOD == 0 && yMOD == 0) {
            return x < y;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i;

    while (true) {
        scanf("%d%d", &n, &mod);
        printf("%d %d\n", n, mod);

        if (!n && !mod) {
            break;
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }

        sort(data, data + n, compare);

        for (i = 0; i < n; i++) {
            printf("%d\n", data[i]);
        }
    }

    return 0;
}

