#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, Len, max, occur[26];
    char s[201], c, dump;

    scanf("%d", &test);
    dump = getchar();
    while (test--) {
        gets(s);
        Len = strlen(s);

        for (i = 0; i < 26; i++) {
            occur[i] = 0;
        }

        for (i = 0; i < Len; i++) {
            c = tolower(s[i]);

            if (c >= 'a' && c <= 'z') {
                occur[c - 97]++;
            }
        }

        max = occur[0];
        for (i = 1; i < 26; i++) {
            if (occur[i] > max) {
                max = occur[i];
            }
        }

        for (i = 0; i < 26; i++) {
            if (occur[i] == max) {
                putchar(i + 97);
            }
        }
        printf("\n");
    }

    return 0;
}

