#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char text[1000], modified[1000];
    int Len, Limit, i, j;

    while (gets(text)) {
        if (!strcmp(text, "DONE")) {
            break;
        }

        Len = strlen(text);
        for (i = 0, j = 0; i < Len; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z') {
                modified[j++] = tolower(text[i]);
            }
        }

        modified[j] = '\0';
        Len = j;
        Limit = Len / 2;

        for (i = 0, j = Len - 1; i <= Limit; i++, j--) {
            /// Not Palindrome
            if (modified[i] != modified[j]) {
                printf("Uh oh..\n");
                break;
            }
        }
        /// Palindrome
        if (i > Limit) {
            printf("You won't be eaten!\n");
        }
    }
    return 0;
}
