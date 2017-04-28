#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int count;
    char c;
} information;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, Len, i, j;
    char s[10000], dump;
    information info[26], temp;

    scanf("%d", &n);
    dump = getchar();

    for (i = 0; i < 26; i++) {
        info[i].count = 0;
        info[i].c = (char) i + 65;
    }

    while (n--) {
        gets(s);
        Len = strlen(s);

        for (i = 0; i < Len; i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                info[toupper(s[i]) - 65].count++;
            }
        }
    }

    for (i = 0; i < 25; i++) {
        for (j = i + 1; j < 26; j++) {
            if ((info[i].count < info[j].count) || (info[i].count == info[j].count && info[i].c > info[j].c)) {
                temp = info[i];
                info[i] = info[j];
                info[j] = temp;
            }
        }
    }

    for (i = 0; i < 26; i++) {
        if (info[i].count != 0) {
            printf("%c %d\n", info[i].c, info[i].count);
        }
    }

    return 0;
}
