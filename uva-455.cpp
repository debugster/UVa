#include <bits/stdc++.h>

using namespace std;

char TEXT[100];
char PATTERN[100];
int LenTEXT;
int LenPATTERN;

bool checkPattern();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i;
    char dump;
    bool found;

    scanf("%d", &test);
    dump = getchar();

    while (test--) {
        scanf("%s", TEXT);

        LenTEXT = strlen(TEXT);

        found = false;
        for (i = 1; i <= LenTEXT; i++) {
            if (LenTEXT % i == 0) {
                PATTERN[0] = '\0'; /// Flushing PATTERN
                strncpy(PATTERN, TEXT, i);
                PATTERN[i] = '\0'; /// Setting NULL to the last
                LenPATTERN = strlen(PATTERN);

                found = checkPattern();
            }

            if (found) break;
        }

        printf("%d\n", LenPATTERN);
        if (test != 0) printf("\n");
    }

    return 0;
}

bool checkPattern()
{
    int i, j, k;

    for (i = 0; i < LenTEXT; i += LenPATTERN) {
        for (j = i, k = 0; k < LenPATTERN; j++, k++) {
            if (TEXT[j] != PATTERN[k]) {
                return false;
            }
        }
    }
    return true;
}
