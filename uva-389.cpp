#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

vector<char>convertedNumber;

ULL anyToDecimal(char *any, int b);
void decimalToAny(ULL dec, int b);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int fromBase, toBase, i, j, convertedSize, blankSpace, Len;
    char originalNumber[1000], dump, error[] = "ERROR", temp[1000];
    ULL decimal;

    while (scanf("%s%d%d", originalNumber, &fromBase, &toBase) == 3) {

            if (fromBase == toBase) {

                Len = strlen(originalNumber);
                i = 0;
                while (originalNumber[i] == '0') {
                    i++;
                }

                if (i == Len) {
                    printf("%7d\n", 0);
                    continue;
                }

                convertedSize = Len - i;

                if (convertedSize <= 7) {
                    blankSpace = 7 - convertedSize;
                    for (j = 1; j <= blankSpace; j++) {
                        printf(" ");
                    }

                    for (; i < Len; i++) {
                        printf("%c", originalNumber[i]);
                    }
                    printf("\n");
                }
                else {
                    printf("%7s\n", error);
                }

                continue;
            }

            if (fromBase == 10) {
                /// Converting Decimal String to Decimal Integer
                decimal = strtoull(originalNumber, NULL, 10);
            }
            else {
                /// Converting given number (String) to Decimal Integer
                decimal = anyToDecimal(originalNumber, fromBase);
            }

            if (toBase == 10) {

                sprintf(temp, "%llu", decimal);

                if (strlen(temp) > 7) {
                    printf("%7s\n", error);
                }
                else {
                    printf("%7s\n", temp);
                }
                strcpy(temp, "\0");
                continue;
            }
            else {
                decimalToAny(decimal, toBase);
                convertedSize = convertedNumber.size();

                if (convertedSize > 7) {
                    printf("%7s\n", error);
                }
                else {
                    blankSpace = 7 - convertedSize;
                    for (i = 1; i <= blankSpace; i++) {
                        printf(" ");
                    }

                    for (i = convertedSize - 1; i >= 0; i--) {
                        printf("%c", convertedNumber[i]);
                    }
                    printf("\n");
                }
            }

        dump = getchar();
        convertedNumber.clear();
    }

    return 0;
}

ULL anyToDecimal(char *any, int b)
{
    int i, j , Len;
    ULL digit, dec = 0;

    Len = strlen(any);

    for (i = 0, j = Len - 1; i < Len; i++, j--) {
        if (any[i] >= '0' && any[i] <= '9') {
            digit = any[i] - '0';
        }
        else if (any[i] >= 'A' && any[i] <= 'F') {
            digit = any[i] - 'A' + 10;
        }

        digit *= pow(b, j);
        dec += digit;
    }

    return dec;
}

void decimalToAny(ULL dec, int b)
{
    int temp;
    char digit;

    do {
        temp = dec % b;

        if (temp >= 0 && temp <= 9) {
            digit = temp + '0';
        }
        else if (temp >= 10 && temp <= 15) {
            digit = temp - 10 + 'A';
        }

        convertedNumber.push_back(digit);
        dec /= b;
    } while (dec != 0);
}
