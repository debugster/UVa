#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, i, count, ans;

    while (scanf("%d", &t) != EOF) {
        count = 0;
        for (i = 1; i <= 5; i++) {
            scanf("%d", &ans);

            if (ans == t) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
