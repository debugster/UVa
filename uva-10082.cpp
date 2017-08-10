#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char MAP[] = ";    M0,.9`12345678 L -    VXSWDFGUHJKNBIO EARYCQZT P][";
    char input[1000];
    int i, Len, test = 1;

    while (gets(input)) {
        Len = strlen(input);

        for (i = 0; i < Len; i++) {
            if (input[i] == ' ') {
                printf(" ");
            }
            else {
                printf("%c", MAP[input[i] - 39]);
            }
        }
        printf("\n");
    }
    return 0;
}
