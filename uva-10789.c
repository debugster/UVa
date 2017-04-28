#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int prime[2002] = {0}, i, j, k, limit, is_prime;
    int test, t, Len, empty, occur[75];
    char s[2002], list[75], dump;

    for (i = 2, j = 0; i <= 2002; i++) {
        is_prime = 1;
        limit = sqrt(i);

        for (k = 2; k <= limit; k++) {
            if (i % k == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime == 1) {
            prime[j++] = i;
        }
    }

    for (i = 48; i <= 122; i++) {
        list[i - 48] = (char) i;
    }


    scanf("%d", &test);
    dump = getchar();
    for (t = 1; t <= test; t++) {
        gets(s);
        Len = strlen(s);

        for (i = 0; i < 75; i++) {
            occur[i] = 0;
        }

        for (i = 0; i < Len; i++) {
            occur[s[i] - 48]++;
        }

        printf("Case %d: ", t);

        empty = 0;
        for (i = 0; i < 75; i++) {
            if (occur[i] != 0) {
                for (k = 0; k < j; k++) {
                    if (occur[i] == prime[k]) {
                        putchar(list[i]);
                        empty = 1;
                    }
                }
            }
        }

        empty == 0 ? printf("empty\n") : printf("\n");
    }

    return 0;
}

