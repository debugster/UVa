#include <bits/stdc++.h>

using namespace std;

unsigned FIBONACCI[91];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, j, test, n, pos, maxPos, Len;
    unsigned *p, *numbers;
    char encrypt[102], encrypt_copy[102], decrypt[102], dump;

    FIBONACCI[1] = 1;
    FIBONACCI[2] = 2;

    /// Table for first 90 Fibonacci Numbers
    for (i = 3; i <= 90; i++) {
        FIBONACCI[i] = FIBONACCI[i - 1] + FIBONACCI[i - 2];
    }

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);

        numbers = (unsigned *) malloc(n * sizeof(unsigned));
        for (i = 0; i < n; i++) {
            scanf("%u", &numbers[i]);
        }
        /// To discard the newline after inputing the last number
        dump = getchar();

        gets(encrypt);
        Len = strlen(encrypt);

        /// Copy only the UPPER case letters for processing
        for (i = 0, j = 0; i < Len; i++) {
            if (encrypt[i] >= 'A' && encrypt[i] <= 'Z') {
                encrypt_copy[j++] = encrypt[i];
            }
        }
        encrypt_copy[j] = '\0';

        /// Clearing previous results
        for (i = 0; i < 102; i++) {
            decrypt[i] = ' ';
        }

        maxPos = -1;
        for (i = 0, j = 0; i < n; i++, j++) {
            /// Finding the index of number[i] in FIBONACCI
            p = upper_bound(FIBONACCI, FIBONACCI + 91, numbers[i]);
            pos = p - FIBONACCI - 1;

            /// Making it fit to 0-th base positional system
            pos--;
            decrypt[pos] = encrypt_copy[j];

            if (pos > maxPos) {
                maxPos = pos;
            }
        }
        decrypt[maxPos + 1] = '\0';
        printf("%s\n", decrypt);
    }

    return 0;
}
