#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char permute[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    int i, j, pos, bin1[3], bin2[3], bin3[3];
    unsigned long long moves, minMoves;

    while (scanf("%d", &bin1[0]) != EOF) {
        for (i = 1; i < 3; i++) {
            scanf("%d", &bin1[i]);
        }

        for (i = 0; i < 3; i++) {
            scanf("%d", &bin2[i]);
        }

        for (i = 0; i < 3; i++) {
            scanf("%d", &bin3[i]);
        }

        minMoves = (unsigned long long) pow(2, 64) - 1;
        for (i = 0; i < 6; i++) {
            moves = 0;
            for (j = 0; j < 3; j++) {
                switch (permute[i][j]) {
                    case 'B':
                        switch (j) {
                            case 0:
                                moves += bin2[0] + bin3[0];
                                break;

                            case 1:
                                moves += bin1[0] + bin3[0];
                                break;

                            case 2:
                                moves += bin1[0] + bin2[0];
                                break;
                        }
                        break;

                    case 'G':
                        switch (j) {
                            case 0:
                                moves += bin2[1] + bin3[1];
                                break;

                            case 1:
                                moves += bin1[1] + bin3[1];
                                break;

                            case 2:
                                moves += bin1[1] + bin2[1];
                                break;
                        }
                        break;

                    case 'C':
                        switch (j) {
                            case 0:
                                moves += bin2[2] + bin3[2];
                                break;

                            case 1:
                                moves += bin1[2] + bin3[2];
                                break;

                            case 2:
                                moves += bin1[2] + bin2[2];
                                break;
                        }
                        break;
                }
            }

            if (moves < minMoves) {
                minMoves = moves;
                pos = i;
            }
        }
        printf("%s %d\n", permute[pos], minMoves);
    }

    return 0;
}
