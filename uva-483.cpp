#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char text[100000];
    int start, _end, Len, i, j;

    while (gets(text)) {
        Len = strlen(text);

        for (i = 0; i < Len; ) {
            if (text[i] == ' ') {
                printf(" ");
                i++;
            }
            else if (text[i] != ' ') {
                start = i;
                while (true) {
                    i++;
                    if (text[i] == ' ' || text[i] == '\0') {
                        break;
                    }
                }
                _end = i - 1;

                for (j = _end; j >= start; j--) {
                    printf("%c", text[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
