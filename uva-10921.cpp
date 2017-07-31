#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int value[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    int Len, i;
    char number[50];

    while (gets(number)) {
        Len = strlen(number);

        for (i = 0; i < Len; i++) {
            if (number[i] >= 'A' && number[i] <= 'Z') {
                printf("%d", value[number[i] - 'A']);
            }
            else {
                printf("%c", number[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
