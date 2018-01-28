#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char Line1[105], Line2[105], s2[105], s3[105], s4[105], s5[105];
    int test, Len, i, j, k;
    bool found;

    scanf("%d", &test);
    getchar();
    while (test--) {
        gets(Line1);
        gets(Line2);

        found = false;

        Len = strlen(Line1);
        for (i = 0; i < Len; i++) {
            if (Line1[i] != '<' && Line1[i] != '>') {
                putchar(Line1[i]);
            }

            if (Line1[i] == '<' && found == false) {
                for (k = 0, j = i + 1; ; k++, j++) {
                    if (Line1[j] == '>') {
                        break;
                    }
                    s2[k] = Line1[j];
                }
                s2[k] = '\0';

                for (k = 0, j++; ; k++, j++) {
                    if (Line1[j] == '<') {
                        break;
                    }
                    s3[k] = Line1[j];
                }
                s3[k] = '\0';

                for (k = 0, j++; ; k++, j++) {
                    if (Line1[j] == '>') {
                        break;
                    }
                    s4[k] = Line1[j];
                }
                s4[k] = '\0';

                for (k = 0, j++; ; k++, j++) {
                    if (j == Len) {
                        break;
                    }
                    s5[k] = Line1[j];
                }
                s5[k] = '\0';

                found = true;
            }
        }
        printf("\n");

        Len = strlen(Line2);
        for (i = 0; i < Len; i++) {
            if (Line2[i] == '.') {
                break;
            }
            putchar(Line2[i]);
        }
        printf("%s%s%s%s\n", s4, s3, s2, s5);
    }

    return 0;
}

