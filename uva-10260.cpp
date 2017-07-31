#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int value[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
    char text[100];
    int i, Len, now, prev;

    while (gets(text)) {
        Len = strlen(text);
        prev = -1;

        for (i = 0; i < Len; i++) {
            now = value[text[i] - 'A'];

            if (now != 0 && now != prev) {
                printf("%d", now);
            }
            prev = now;
        }
        printf("\n");
    }
    return 0;
}
