#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int side[3], temp, i, j;

    while (scanf("%d%d%d", &side[0], &side[1], &side[2]) && side[0] != 0 && side[1] != 0 && side[2] != 0) {
        for (i = 0; i < 2; i++) {
            for (j = i + 1; j < 3; j++) {
                if (side[i] > side[j]) {
                    temp = side[i];
                    side[i] = side[j];
                    side[j] = temp;
                }
            }
        }

        if (side[0] * side[0] + side[1] * side[1] == side[2] * side[2]) {
            printf("right\n");
        }
        else {
            printf("wrong\n");
        }
    }
    return 0;
}
