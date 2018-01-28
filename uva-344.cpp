#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char ones[][10] = {
                        "",
                        "i",
                        "ii",
                        "iii",
                        "iv",
                        "v",
                        "vi",
                        "vii",
                        "viii",
                        "ix"
                        };
    char tens[][10] = {
                        "",
                        "x",
                        "xx",
                        "xxx",
                        "xl",
                        "l",
                        "lx",
                        "lxx",
                        "lxxx",
                        "xc"
                        };

    int DP[101][5]; /// 0 - i, 1 - v, 2 - x, 3 - l, 4 - c
    int Letters[5]; /// 0 - i, 1 - v, 2 - x, 3 - l, 4 - c
    int k, j, Len, q, r;
    char roman[10];

    DP[1][0] = 1;
    DP[1][1] = DP[1][2] = DP[1][3] = DP[1][4] = 0;

    for (k = 2; k <= 99; k++) {
        q = k / 10;
        r = k % 10;

        strcpy(roman, tens[q]);
        strcat(roman, ones[r]);

        Len = strlen(roman);

        Letters[0] = Letters[1] = Letters[2] = Letters[3] = Letters[4] = 0;
        for (j = 0; j < Len; j++) {
            switch (roman[j]) {
                case 'i':
                    Letters[0]++;
                    break;

                case 'v':
                    Letters[1]++;
                    break;

                case 'x':
                    Letters[2]++;
                    break;

                case 'l':
                    Letters[3]++;
                    break;

                case 'c':
                    Letters[4]++;
                    break;
            }
        }

        for (j = 0; j < 5; j++) {
            DP[k][j] = DP[k - 1][j] + Letters[j];
        }
    }

    for (k = 0; k < 5; k++) {
        DP[100][k] = DP[99][k];
    }
    DP[100][4]++;

    while (scanf("%d", &k)) {
        if (!k) {
            break;
        }

        printf("%d: %d i, %d v, %d x, %d l, %d c\n", k, DP[k][0], DP[k][1], DP[k][2], DP[k][3], DP[k][4]);
    }

    return 0;
}

