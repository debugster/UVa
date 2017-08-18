#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, n[5];
    bool valid;

    scanf("%d", &test);
    while (test--) {
        valid = true;
        for (i = 0; i < 5; i++) {
            scanf("%d", &n[i]);

            if (valid && i >= 1) {
                if (n[i] != n[i - 1] + 1) {
                    valid = false;
                }
            }
        }

        valid ? printf("Y\n") : printf("N\n");
    }
    return 0;
}
