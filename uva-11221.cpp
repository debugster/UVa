#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, j, k, Len, n;
    char text[10002], textCopy[10002], **table, dump;
    bool valid;

    scanf("%d", &test);
    dump = getchar();
    for (t = 1; t <= test; t++) {
        gets(text);
        Len = strlen(text);

        for (i = 0, j = 0; i < Len; i++) {
            if (text[i] >= 'a' && text[i] <= 'z') {
                textCopy[j++] = text[i];
            }
        }
        textCopy[j] = '\0';
        Len = j;
        n = sqrt(Len);
        valid = false;
        if (n * n == Len) {
            table = (char **) malloc(n * sizeof(char *));
            for (i = 0; i < n; i++) {
                table[i] = (char *) malloc(n * sizeof(char));
            }

            for (i = 0, k = 0; i < n; i++) {
                for (j = 0; j < n; j++, k++) {
                    table[i][j] = textCopy[k];
                }
            }

            /*
            for (i = 0, k = 0; i < n; i++) {
                for (j = 0; j < n; j++, k++) {
                    printf("%c ", table[i][j]);
                }
                printf("\n");
            }
            */
            /// Reading in the 2nd way
            for (i = 0, k = 0; i < n; i++) {
                for (j = 0; j < n; j++, k++) {
                    text[k] = table[j][i];
                }
            }
            text[k] = '\0';
            //printf("%s\n%s\n", text, textCopy);
            if (!strcmp(text, textCopy)) {
                valid = true;
            }

            /// Reading in the 3rd way
            if (valid) {
                for (i = n - 1, k = 0; i >= 0; i--) {
                    for (j = n - 1; j >= 0; j--, k++) {
                        text[k] = table[i][j];
                    }
                }
                if (strcmp(text, textCopy)) {
                    valid = false;
                }
            }

            /// Reading in the 4th way
            if (valid) {
                for (i = n - 1, k = 0; i >= 0; i--) {
                    for (j = n - 1; j >= 0; j--, k++) {
                        text[k] = table[j][i];
                    }
                }
                if (strcmp(text, textCopy)) {
                    valid = false;
                }
            }
        }

        printf("Case #%d:\n", t);

        if (valid) {
            printf("%d\n", n);
        }
        else {
            printf("No magic :(\n");
        }
    }
    return 0;
}
