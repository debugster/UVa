#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, n;
    bool valid;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        printf("Set #%d: ", t);

        valid = true;
        for (i = 1; i <= 13; i++) {
            scanf("%d", &n);
            if (n <= 0) {
                valid = false;
            }
        }

        valid ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}
