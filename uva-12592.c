#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char **slogans;
    char s[101], dump;
    int n, i, j, t, m;
    scanf("%d", &n);
    dump = getchar();
    t = n * 2;
    slogans = malloc(t * sizeof(char*));
    for (i = 0; i < t; i++) {
        slogans[i] = malloc(101 * sizeof(char));
        gets(slogans[i]);
    }
    scanf("%d", &m);
    dump = getchar();
    for (j = 1; j <= m; j++) {
        gets(s);
        for (i = 0; i < t; i++) {
            if(!strcmp(s, slogans[i])) {
                printf("%s\n", slogans[i + 1]);
                break;
            }
        }
    }
    return 0;
}
