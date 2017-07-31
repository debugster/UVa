#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, Len, i, j, number;
    char input[5000], numberStr[5000], c;

    scanf("%d", &test);
    c = getchar(); /// Discarding carriage return
    for (t = 1; t <= test; t++) {
        gets(input);
        Len = strlen(input);

        printf("Case %d: ", t);

        for (i = 0; i < Len; ) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                c = input[i];
                j = 0;
                i++;
                while (input[i] >= '0' && input[i] <= '9') {
                    numberStr[j++] = input[i++];
                }
                numberStr[j] = '\0';
                number = atoi(numberStr);

                for (j = 1; j <= number; j++) {
                    putchar(c);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
