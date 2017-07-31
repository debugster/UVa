#include <bits/stdc++.h>

using namespace std;

bool isPalindrome();
bool isMirrorPalindrome();
bool isMirrorString();

char TEXT[100];
int LenTEXT;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test = 1;

    while (gets(TEXT)) {
        LenTEXT = strlen(TEXT);

        printf("%s -- ", TEXT);

        /// If a string is palindrome, there is a chance for it to be a mirrored palindrome
        if (isPalindrome()) {
            if(isMirrorPalindrome()) {
                printf("is a mirrored palindrome.\n");
            }
            else {
                printf("is a regular palindrome.\n");
            }
        }
        /// If a string is not palindrome, there is a chance for it to be a mirrored string
        else {
            if (isMirrorString()) {
                printf("is a mirrored string.\n");
            }
            else {
                printf("is not a palindrome.\n");
            }
        }
        printf("\n");

    }
    return 0;
}

bool isPalindrome()
{
    int i, j, Limit;

    Limit = LenTEXT / 2;
    for (i = 0, j = LenTEXT - 1; i < Limit; i++, j--) {
        if (TEXT[i] != TEXT[j]) {
            return false;
        }
    }
    return true;
}

bool isMirrorPalindrome()
{
    int i = 0;

    for (i = 0; i < LenTEXT; i++) {
        switch (TEXT[i]) {
            case 'A':
            case 'H':
            case 'I':
            case 'M':
            case 'O':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case '1':
            case '8':
                continue;
            default:
                return false;
        }
    }
    return true;
}

bool isMirrorString()
{
    int i;

    for (i = 0; i < LenTEXT; i++) {
        switch (TEXT[i]) {
            case '3':
                TEXT[i] = 'E';
                break;

            case 'J':
                TEXT[i] = 'L';
                break;

            case '2':
                TEXT[i] = 'S';
                break;

            case '5':
                TEXT[i] = 'Z';
                break;

            case 'E':
            case 'L':
            case 'S':
            case 'Z':

            case 'A':
            case 'H':
            case 'I':
            case 'M':
            case 'O':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case '1':
            case '8':
                break;

            default:
                return false;
        }
    }

    return isPalindrome();
}
