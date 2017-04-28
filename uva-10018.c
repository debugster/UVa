#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome(char *s);
void reverse_copy(char *from, char *to);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, is_pal, count;
    long long n, n_rev;
    char s1[100], s2[100];

    scanf("%d", &test);
    while (test--) {
        scanf("%lld", &n);

        is_pal = 0;
        count = 0;

        while (is_pal == 0) {
            count++;
            sprintf(s1, "%lld", n);
            reverse_copy(s1, s2);

            n_rev = strtoll(s2, NULL, 10);

            n += n_rev;
            sprintf(s1, "%lld", n);

            is_pal = is_palindrome(s1);
        }

        printf("%d %lld\n", count, n);
    }
    return 0;
}

int is_palindrome(char *s)
{
    int i, j, Len, limit, is_pal = 1;
    Len = strlen(s);
    limit = Len / 2;

    for (i = 0, j = Len - 1; i <= limit; i++, j--) {
        if (s[i] != s[j]) {
            is_pal = 0;
            break;
        }
    }
    return is_pal;
}

void reverse_copy(char *from, char *to)
{
    int i, j, Len = strlen(from);

    for (i = Len - 1, j = 0; i >= 0; i--, j++) {
        to[j] = from[i];
    }

    to[j] = '\0';
}
