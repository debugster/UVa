#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char c;

    while (scanf("%c", &c) != EOF) {
        if (c != '\n') {
            c -= 7;
        }
        putchar(c);
    }
    return 0;
}
