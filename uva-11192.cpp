#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int g, i, j, m, Len, gLen;
    char text[102], textRev[102];

    while (scanf("%d", &g)) {
        if (!g) {
            break;
        }

        scanf("%s", text);
        Len = strlen(text);
        gLen = Len / g;

        for (i = gLen - 1, j = 0; i < Len; i += gLen, j += gLen) {
            for (m = i; m >= j; m--) {
                printf("%c", text[m]);
            }
        }
        printf("\n");
    }
    return 0;
}
