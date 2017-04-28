#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char c;
    int count = 0;

    while (scanf("%c", &c) != EOF) {
        if (c == '"') {
            count++;

            if (count % 2 == 1) {
                printf("``");
            }
            else {
                printf("\'\'");
            }
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
