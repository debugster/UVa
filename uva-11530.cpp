#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int MAP[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    char text[102], dump;
    int test, t, i, Len, total;

    scanf("%d", &test);
    dump = getchar();
    for (t = 1; t <= test; t++) {
        gets(text);

        total = 0;
        Len = strlen(text);
        for (i = 0; i < Len; i++) {
            if (text[i] == ' ') {
                total++;
            }
            else {
                total += MAP[text[i] - 'a'];
            }
        }
        printf("Case #%d: %d\n", t, total);
    }
    return 0;
}
