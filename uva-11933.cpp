#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

vector<char>convertedNumber;
vector<char>numberA;
vector<char>numberB;
vector<int>indexOnes;

ULL binaryToDecReverse(vector<char> &num);
void decimalToBinary(ULL dec);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ULL n, A, B;
    int numberSize, i, j;

    while (scanf("%llu", &n) && n != 0) {
        decimalToBinary(n);
        numberSize = convertedNumber.size();

        numberA.assign(numberSize, '0');
        numberB.assign(numberSize, '0');

        /*
        for (int i = 0; i < indexOnes.size(); i++) {
                printf("%d\n", indexOnes[i]);
        }
        printf("\n");
        */

        for (i = 0; i < indexOnes.size(); i++) {
                j = i + 1;

                /// Inserting 1's to numberA
                if (j % 2 == 1) {
                    numberA[indexOnes[i]] = '1';
                }
                /// Inserting 1's to numberB
                else {
                    numberB[indexOnes[i]] = '1';
                }
        }

        /*
        for (i = 0; i < numberSize; i++) {
            printf("%c", numberA[i]);
        }
        printf("\n");

        for (i = 0; i < numberSize; i++) {
            printf("%c", numberB[i]);
        }
        printf("\n");
        */

        A = binaryToDecReverse(numberA);
        B = binaryToDecReverse(numberB);

        printf("%llu %llu\n", A, B);

        convertedNumber.clear();
        numberA.clear();
        numberB.clear();
        indexOnes.clear();
    }

    return 0;
}

ULL binaryToDecReverse(vector<char> &num)
{
    ULL dec = 0, digit;
    int i;

    for (i = 0; i < num.size(); i++) {
        digit = num[i] - '0';

        digit *= pow(2, i);
        dec += digit;
    }

    return dec;
}

void decimalToBinary(ULL dec)
{
    int temp, i;
    char digit;

    i = 0;
    do {
        temp = dec % 2;
        digit = temp + '0';
        convertedNumber.push_back(digit);
        dec /= 2;

        if (temp == 1) {
            indexOnes.push_back(i);
        }
        i++;
    } while (dec != 0);
}
