#include <stdio.h>
#include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, j, Len;
    double money, av;
    char s[100], s2[100], s3[100];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        av = 0;
        for (i = 0; i < 12; i++) {
            scanf("%lf", &money);
            av += money;
        }

        av /= 12.0;
        printf("%d $", t);
        sprintf(s, "%.2lf", av);
        //puts(s);
        Len = strlen(s);
        //printf("%d\n", Len);

        for (i = Len - 1, j = 0; i >= 0; i--, j++) {
            s2[j] = s[i];
        }
        s2[j] = '\0';
        //puts(s2);

        for (i = 0, j = 0; i < Len;) {
            if (i > 3) {
                if (i % 3 == 0) {
                    s3[j] = ',';
                    j++;
                    s3[j] = s2[i];
                    i++;
                    j++;

                }
                else {
                    s3[j] = s2[i];
                    i++;
                    j++;
                }
            }
            else {
                s3[j] = s2[i];
                i++;
                j++;
            }
        }
        s3[j] = '\0';
        Len = strlen(s3);
        for (i = Len - 1; i >= 0; i--) {
            putchar(s3[i]);
        }
        printf("\n");

    }
    return 0;
}
