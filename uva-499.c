#include <stdio.h>
#include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char s[10000];
    int capital[26], small[26];
    int Len, i, max;

    while (gets(s)) {
        Len = strlen(s);

        for (i = 0; i < 26; i++) {
            capital[i] = small[i] = 0;
        }

        for (i = 0; i < Len; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                capital[s[i] - 65]++;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                small[s[i] - 97]++;
            }
        }

        max = capital[0];
        for (i = 0; i < 26; i++) {
            if (capital[i] > max) {
                max = capital[i];
            }

            if (small[i] > max) {
                max = small[i];
            }
        }

        for (i = 0; i < 26; i++) {
            if (capital[i] == max) {
                printf("%c", i + 65);
            }
        }
        for (i = 0; i < 26; i++) {
            if (small[i] == max) {
                printf("%c", i + 97);
            }
        }

        printf(" %d\n", max);
    }
    return 0;
}
