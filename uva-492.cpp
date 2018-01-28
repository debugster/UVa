#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char Line[1000005];
    string word;
    int Len, i, j;

    while (gets(Line)) {
        Len = strlen(Line);
        for (i = 0; i < Len; i++) {
            if (tolower(Line[i]) >= 'a' && tolower(Line[i]) <= 'z') {
                word.clear();
                while (tolower(Line[i]) >= 'a' && tolower(Line[i]) <= 'z') {
                    word += Line[i];
                    i++;
                }
                i--;

                switch (tolower(word[0])) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        printf("%say", word.c_str());
                        break;

                    default:
                        for (j = 1; j < word.size(); j++) {
                            putchar(word[j]);
                        }
                        putchar(word[0]);
                        printf("ay");
                        break;
                }
            }
            else {
                putchar(Line[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}

