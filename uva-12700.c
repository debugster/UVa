#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, m, b, w, tie, a;
    char r, dump;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {

        b = w = tie = a = 0;

        scanf("%d", &n);
        dump = getchar();
        m = n;

        while (n--) {
            r = getchar();

            switch (r) {
                case 'B':
                    b++;
                    break;
                case 'W':
                    w++;
                    break;
                case 'T':
                    tie++;
                    break;
                case 'A':
                    a++;
                    break;
            }
        }

        printf("Case %d: ", t);

        if (a == m) {
            printf("ABANDONED\n");
        }
        else if (b == m || b == (m - a)) {
            printf("BANGLAWASH\n");
        }
        else if (w == m || w == (m - a)) {
            printf("WHITEWASH\n");
        }
        else if (b > w) {
            printf("BANGLADESH %d - %d\n", b, w);
        }
        else if (b < w) {
            printf("WWW %d - %d\n", w, b);
        }
        else {
            printf("DRAW %d %d\n", b, tie);
        }
    }
    return 0;
}
