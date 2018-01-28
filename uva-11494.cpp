#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, sX, sY, desX, desY, moves;

    while (scanf("%d%d%d%d", &sX, &sY, &desX, &desY)) {

        if (!sX && !sY && !desX && !desY) {
            break;
        }

        /// If source and destination are the same cell
        if (sX == desX && sY == desY) {
            moves = 0;
        }
        /// If source and destination are in same row or same column
        else if (sX == desX || sY == desY) {
            moves = 1;
        }
        else {
            moves = 2;

            /// Checking whether destination can be reached diagonally
            for (i = 1; i <= 8; i++) {
                if ((sX + i == desX && sY + i == desY) || (sX + i == desX && sY - i == desY) || (sX - i == desX && sY + i == desY) || (sX - i == desX && sY - i == desY)) {
                    moves = 1;
                    break;
                }
            }
        }

        printf("%d\n", moves);
    }

    return 0;
}
