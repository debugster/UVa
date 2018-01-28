#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char Line[100001];
    int i, j, Len, num;

    while (gets(Line)) {

        if (Line[0] == '\0') {
            printf("\n");
            continue;
        }

        Len = strlen(Line);
        num = 0;
        for (i = 0; i < Len; i++) {
            if (Line[i] >= '0' && Line[i] <= '9') {
                num += Line[i] - 48;
            }
            else if (Line[i] == '!') {
                printf("\n");
            }
            else {
                if (Line[i] == 'b') {
                    Line[i] = ' ';
                }

                for (j = 1; j <= num; j++) {
                    putchar(Line[i]);
                }
                num = 0;
            }
        }
        printf("\n");
    }

    return 0;
}

