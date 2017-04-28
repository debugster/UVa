#include <stdio.h>
#include <stdlib.h>

int check_parity(int **num, int n);
void change_bit(int *pos);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, j, is_pair;
    int **num;

    while (scanf("%d", &n) && n != 0) {
        n++; // n is incremented to reduce the time of operations -> (n + 1)
        num = (int **) malloc(n * sizeof(int *));

        for (i = 1; i < n; i++) {
            num[i] = (int *) malloc(n * sizeof(int));

            for (j = 1; j < n; j++) {
                scanf("%d", &num[i][j]);
            }
        }

        is_pair = check_parity(num, n);

        if (is_pair == 1) {
            printf("OK\n");
        }
        else {
            for (i = 1; i < n; i++) {
                for (j = 1; j < n; j++) {
                    change_bit(&num[i][j]);

                    is_pair = check_parity(num, n);

                    if (is_pair == 1) {
                        printf("Change bit (%d,%d)\n", i, j);
                        break;
                    }
                    else {
                        change_bit(&num[i][j]); // reverting back the change
                    }
                }

                if (is_pair == 1) {
                    break;
                }
            }
            if (is_pair == 0) {
                printf("Corrupt\n");
            }
        }
    }
    return 0;
}

int check_parity(int **num, int n)
{
    int i, j, sum, is_pair = 1;


    for (i = 1; i < n; i++) {
        sum = 0;
        for (j = 1; j < n; j++) {
            sum += num[i][j];
        }

        if (sum % 2 != 0) {
            is_pair = 0;
            break;
        }
    }

    if (is_pair == 1) {
        for (j = 1; j < n; j++) {
            sum = 0;
            for (i = 1; i < n; i++) {
                sum += num[i][j];
            }
            if (sum % 2 != 0) {
                is_pair = 0;
                break;
            }
        }
    }

    return is_pair;
}

void change_bit(int *pos)
{
    if (*pos == 0) {
        *pos = 1;
    }
    else if (*pos == 1) {
        *pos = 0;
    }
}
