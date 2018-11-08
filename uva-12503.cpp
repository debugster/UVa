#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, currentPos, i, digit, Left, Right;
    char instructionSet[MAX + 1], command[50], dump1[20], dump2[20];

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        getchar();

        Left = Right = 0;
        for (i = 1; i <= n; i++) {
            gets(command);

            if (!strcmp(command, "LEFT")) {
                Left++;
                instructionSet[i] = 'L';
            }
            else if (!strcmp(command, "RIGHT")) {
                Right++;
                instructionSet[i] = 'R';
            }
            else {
                sscanf(command, "%s %s %d", dump1, dump2, &digit);
                instructionSet[i] = instructionSet[digit];

                if (instructionSet[i] == 'L') {
                    Left++;
                }
                else {
                    Right++;
                }
            }
        }

        currentPos = abs(Left - Right);

        if (Left > Right) {
            currentPos *= -1;
        }

        printf("%d\n", currentPos);
    }

    return 0;
}
