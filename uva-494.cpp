#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char text[10002];
    int i, Len, word;

    while (gets(text)) {
        Len = strlen(text);
        word = 0;
        for (i = 0; i < Len; ) {
            if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z') {
                while (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z') {
                    i++;
                }
                word++;
            }
            else {
                i++;
            }
        }
        printf("%d\n", word);
    }

    return 0;
}

