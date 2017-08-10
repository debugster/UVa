#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char HELLO[6][20] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
    char LANG[6][20] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
    char input[20];
    int test = 1, i;

    while (gets(input)) {
        if (!strcmp(input, "#")) {
            break;
        }

        printf("Case %d: ", test++);

        for (i = 0; i < 6; i++) {
            if (!strcmp(input, HELLO[i])) {
                printf("%s\n", LANG[i]);
                break;
            }
        }

        if (i == 6) {
            printf("UNKNOWN\n");
        }
    }
    return 0;
}
