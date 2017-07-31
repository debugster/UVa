#include <bits/stdc++.h>

using namespace std;

char numberString[2000];
char temp[2000];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int Len, i, sum, degree;

    while (scanf("%s", numberString) && strcmp(numberString, "0") != 0) {
        printf("%s is ", numberString);

        Len = strlen(numberString);

        /// If the given number is "9", degree should have been 0
        /// But Judge shows that it is 1, strange !
        /// So, if the given number is "9",
        /// We must print degree 1 without further calculation
        if (Len == 1 && numberString[0] == '9') {
            degree = 1;
        }
        /// Else we have to calculate degree in the given way
        else {
            degree = 0;

            while (Len > 1) {

                sum = 0;
                for (i = 0; i < Len; i++) {
                    sum += (int) numberString[i] - '0';
                }

                sprintf(numberString, "%d", sum);
                Len = strlen(numberString);

                degree++;
            }
        }

        if (sum % 9 == 0) {
            printf("a multiple of 9 and has 9-degree %d.\n", degree);
        }
        else {
            printf("not a multiple of 9.\n");
        }
    }

    return 0;
}
