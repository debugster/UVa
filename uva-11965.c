#include <stdio.h>
#include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, i, Len;
    char s[501], dump;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        printf("Case %d:\n", t);
        scanf("%d%c", &n, &dump);
        while (n--) {
            gets(s);
            Len = strlen(s);

            for (i = 0; i < Len; ) {
                if (s[i] != ' ') {
                    putchar(s[i]);
                    i++;
                }
                else if (s[i] == ' ' && s[i + 1] != ' ' && i != Len - 1) {
                    putchar(s[i]);
                    i++;
                }
                else if (s[i] == ' ') {
                    putchar(s[i]);

                    while (s[i] == ' ') {
                        i++;
                    }
                }
            }
            printf("\n");
        }
        if (t != test) {
            printf("\n");
        }
    }
    return 0;
}
