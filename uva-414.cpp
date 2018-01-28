#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, j, min, total, spaceCount[20];
    char Line[30], dump;

    while (scanf("%d", &n)) {
        getchar();

        if (!n) {
            break;
        }

        min = 25;
        for (i = 1; i <= n; i++) {
            gets(Line);

            spaceCount[i] = 0;
            for (j = 0; j < 25; j++) {
                if (Line[j] == ' ') {
                    spaceCount[i]++;
                }
            }

            if (spaceCount[i] < min) {
                min = spaceCount[i];
            }
        }

        total = 0;
        for (i = 1; i <= n; i++) {
            total += abs(spaceCount[i] - min);
        }

        printf("%d\n", total);
    }

    return 0;
}

