#include <bits/stdc++.h>

using namespace std;

const int MAX = 205;

char A[MAX];
char B[MAX];
char C[MAX];
int LenA;
int LenB;
int LenC;

void bigAddition();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, j, Len;
    char tempA[MAX], tempB[MAX];

    scanf("%d", &test);
    while (test--) {
        scanf("%s %s", tempA, tempB);

        Len = strlen(tempA);
        for (i = 0, j = Len - 1; i < Len; i++, j--) {
            A[i] = tempA[j];
        }
        A[i] = '\0';

        Len = strlen(tempB);
        for (i = 0, j = Len - 1; i < Len; i++, j--) {
            B[i] = tempB[j];
        }
        B[i] = '\0';

        bigAddition();

        Len = strlen(C);
        for (i = 0, j = Len - 1; i < Len; i++, j--) {
            tempA[i] = C[j];
        }
        tempA[i] = '\0';

        if (tempA[0] == '0') {
            i = 0;
            while (true) {
                if (tempA[i] == '0' && tempA[i + 1] != '0') {
                    break;
                }
                i++;
            }

            for (j = i + 1; j < Len; j++) {
                putchar(tempA[j]);
            }
            putchar('\n');
        }
        else {
            printf("%s\n", tempA);
        }
    }

    return 0;
}

void bigAddition()
{
    int LenDif, i;

    LenA = strlen(A);
    LenB = strlen(B);

    /// We assume that, A is longer than or equal to B
    /// So, if B is longer than A, we have to swap A and B
    if (LenB > LenA) {
        char *temp = (char *) malloc(LenB * sizeof(char));

        strcpy(temp, A);
        strcpy(A, B);
        strcpy(B, temp);

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
            B[i] = B[i - LenDif];
        }

        /// Putting a null character to the end and calculate LenB again
        B[LenA] = '\0';
        /// LenB = strlen(B);
        LenB = LenA; /// /// Because, we know it for sure, need not call strlen()

        /// Shifting Done !
        /// Now, we have to put 0s in first LenDif bits of B
        for (i = 0; i < LenDif; i++) {
            B[i] = '0';
        }
    }

    /// We'are going to put the result in C
    /// C will have either the length of LenA or LenA + 1
    /// So, putting a trailing 0 in both A and B will make our calculation easier
    /// Now, we are going to shift A and B 1-bit to the right and place a 0 at the first bit
    for (i = LenA; i > 0; i--) {
        A[i] = A[i - 1];
        B[i] = B[i - 1];
    }
    /// Putting a 0 to the first bit
    A[0] = '0';
    B[0] = '0';
    /// Putting a null character to the end and calculate LenA and LenB again
    A[LenA + 1] = '\0';
    B[LenB + 1] = '\0';
    /// LenA = strlen(A);
    /// LenB = strlen(B);
    LenA++; /// Because, we know it for sure, need not call strlen()
    LenB++;

    /// Now, it is the time to perform addition

    int sum, carry = 0;

    /// Since, we put leading 0 in both A and B, C will have maximum length of LenA
    C[LenA] = '\0';
    for (i = LenA - 1; i >= 0; i--) {
        sum = A[i] - '0' + B[i] - '0' + carry;

        if (sum > 9) {
            C[i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        else {
            C[i] = sum + '0';
            carry = 0;
        }
    }

    /// If C have leading 0, Lets remove it
    if (C[0] == '0') {
        for (i = 0; i < LenA - 1; i++) {
            C[i] = C[i + 1];
        }
        C[LenA - 1] = '\0';
    }
}

