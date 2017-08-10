#include <bits/stdc++.h>

using namespace std;

const int MAX = 800;
const int SIZE = 366;

char FACTORIAL[SIZE + 1][MAX];
int DigitCount[SIZE + 1][10];
char A_Copy[MAX];
char B_Copy[MAX];
char C[MAX];
char PRODUCT[MAX];

void bigAddition(char *A, char *B);
void bigMultiplication(char *M1, char *M2);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int num, i, j, Limit, index;
    char numStr[10];

    strcpy(FACTORIAL[0], "1");

    for (num = 1; num <= SIZE; num++) {
        sprintf(numStr, "%d", num);

        bigMultiplication(FACTORIAL[num - 1], numStr);

        strcpy(FACTORIAL[num], PRODUCT);
        numStr[0] = '\0';
    }

    for (i = 0; i <= SIZE; i++) {
        Limit = strlen(FACTORIAL[i]);
        for (j = 0; j < Limit; j++) {
            index = FACTORIAL[i][j] - '0';
            DigitCount[i][index]++;
        }
    }

    //printf("Ready\n");

    while (scanf("%d", &num)) {
        if (num == 0) {
            break;
        }

        printf("%d! --\n", num);
        printf("   (0)  %3d    (1)  %3d    (2)  %3d    (3)  %3d    (4)  %3d\n", DigitCount[num][0], DigitCount[num][1], DigitCount[num][2], DigitCount[num][3], DigitCount[num][4]);
        printf("   (5)  %3d    (6)  %3d    (7)  %3d    (8)  %3d    (9)  %3d\n", DigitCount[num][5], DigitCount[num][6], DigitCount[num][7], DigitCount[num][8], DigitCount[num][9]);
    }

    return 0;
}

void bigAddition(char *A, char *B)
{
    int LenA, LenB, LenDif, i;

    strcpy(A_Copy, A);
    strcpy(B_Copy, B);

    LenA = strlen(A_Copy);
    LenB = strlen(B_Copy);

    /// We assume that, A is longer than or equal to B
    /// So, if B is longer than A, we have to swap A and B
    if (LenB > LenA) {
        char *temp = (char *) malloc(LenB * sizeof(char));

        strcpy(temp, A_Copy);
        strcpy(A_Copy, B_Copy);
        strcpy(B_Copy, temp);

        /// So, we have to swap LenA and LenB too
        int tempLen = LenA;
        LenA = LenB;
        LenB = tempLen;

        free(temp);
    }

    /// We have to shift the shorter number to the right
    /// Because, we perform addition bit by bit starting from the rightmost bit

    /// Difference between lengths
    LenDif = LenA - LenB;

    /// If LenDif is 0, we don't need any shifting operation
    if (LenDif != 0) {

        for (i = LenA - 1; i >= LenDif; i--) {
            B_Copy[i] = B_Copy[i - LenDif];
        }

        /// Putting a null character to the end and calculate LenB again
        B_Copy[LenA] = '\0';
        /// LenB = strlen(B);
        LenB = LenA; /// /// Because, we know it for sure, need not call strlen()

        /// Shifting Done !
        /// Now, we have to put 0s in first LenDif bits of B
        for (i = 0; i < LenDif; i++) {
            B_Copy[i] = '0';
        }
    }

    /// We'are going to put the result in C
    /// C will have either the length of LenA or LenA + 1
    /// So, putting a trailing 0 in both A and B will make our calculation easier
    /// Now, we are going to shift A and B 1-bit to the right and place a 0 at the first bit
    for (i = LenA; i > 0; i--) {
        A_Copy[i] = A_Copy[i - 1];
        B_Copy[i] = B_Copy[i - 1];
    }
    /// Putting a 0 to the first bit
    A_Copy[0] = '0';
    B_Copy[0] = '0';
    /// Putting a null character to the end and calculate LenA and LenB again
    A_Copy[LenA + 1] = '\0';
    B_Copy[LenB + 1] = '\0';
    /// LenA = strlen(A);
    /// LenB = strlen(B);
    LenA++; /// Because, we know it for sure, need not call strlen()
    LenB++;

    /// Now, it is the time to perform addition

    int sum, carry = 0;

    /// Since, we put trailing 0 in both A and B, C will have maximum length of LenA
    C[LenA] = '\0';
    for (i = LenA - 1; i >= 0; i--) {
        sum = A_Copy[i] - '0' + B_Copy[i] - '0' + carry;

        if (sum > 9) {
            C[i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        else {
            C[i] = sum + '0';
            carry = 0;
        }
    }

    /// If C have trailing 0, Lets remove it
    if (C[0] == '0') {
        for (i = 0; i < LenA - 1; i++) {
            C[i] = C[i + 1];
        }
        C[LenA - 1] = '\0';
    }
}

void bigMultiplication(char *M1, char *M2)
{
    int LenM1, LenM2, LenTemp, i, j, k, L, m, prod, carry;
    char *tempProduct, *tempProductReverse;

    LenM1 = strlen(M1); /// Length of First Number
    LenM2 = strlen(M2); /// Length of Second Number

    /// Outer Loop will visit every digit of Second Number from Right to Left
    /// Variable m will keep counting how many trailing 0's (Zero) to be added -
    /// to the right side of the intermediate products
    for (i = LenM2 - 1, m = 0; i >= 0; i--, m++) {

        /// tempProduct will store the result in reverse order
        tempProduct = (char *) malloc(MAX * sizeof(char));
        /// tempProductReverse will store the result in actual order
        tempProductReverse = (char *) malloc(MAX * sizeof(char));

        /// Adding trailing 0's
        for (k = 0; k < m; k++) {
            tempProduct[k] = '0';
        }

        carry = 0;
        /// Inner Loop will visit every digit of First Number from Right to Left
        /// The resultant digit will be placed at k-th position of tempProduct
        for (j = LenM1 - 1; j >= 0; j--, k++) {
            prod = (M1[j] - '0') * (M2[i] - '0') + carry;

            if (prod > 9) {
                tempProduct[k] = (prod % 10) + '0';
                carry = prod / 10;
            }
            else {
                tempProduct[k] = prod + '0';
                carry = 0;
            }
        }
        /// If carry is not zero, that means we need an extra bit
        /// k is already incremented
        /// So, place the carry digit at k-th position
        /// and place NULL at (k + 1)-th position
        if (carry != 0) {
            tempProduct[k] = carry + '0';
            tempProduct[k + 1] = '\0';
        }
        /// If carry is zero, then place NULL at k-th position
        else {
            tempProduct[k] = '\0';
        }

        /// Keep the value of tempProduct reversely in tempProductReverse
        /// Actually, tempProductReverse will have the original value
        LenTemp = strlen(tempProduct);
        for (k = LenTemp - 1, L = 0; k >= 0; k--, L++) {
            tempProductReverse[L] = tempProduct[k];
        }
        /// Manually keeping NULL at the Rightmost bit
        tempProductReverse[L] = '\0';

        /// We'll use variable PRODUCT to keep the latest result at any time
        /// If m is zero, that means tempProductReverse will have the First intermediate product
        /// So, directly copy it into PRODUCT
        if (m == 0) {
            strcpy(PRODUCT, tempProductReverse);
        }
        /// If m is not zero, Add tempProductReverse with previous PRODUCT
        /// and then keep the sum (came with Global Variable C) into PRODUCT
        else {
            bigAddition(PRODUCT, tempProductReverse);
            strcpy(PRODUCT, C);
        }

        free(tempProduct);
        free(tempProductReverse);
    }
}
