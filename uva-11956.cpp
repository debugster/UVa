#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int data[100];
    char command[MAX + 5];
    int test, t, i, Len, pointer;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%s", command);
        Len = strlen(command);

        memset(data, 0, sizeof(data));
        pointer = 0;

        for (i = 0; i < Len; i++) {
            switch (command[i]) {
                case '>':
                    pointer++;
                    if (pointer == 100) {
                        pointer = 0;
                    }
                    break;

                case '<':
                    pointer--;
                    if (pointer == -1) {
                        pointer = 99;
                    }
                    break;

                case '+':
                    data[pointer]++;
                    if (data[pointer] == 256) {
                        data[pointer] = 0;
                    }
                    break;

                case '-':
                    data[pointer]--;
                    if (data[pointer] == -1) {
                        data[pointer] = 255;
                    }
                    break;
            }
        }
        printf("Case %d:", t);
        for (i = 0; i < 100; i++) {
            printf(" %02X", data[i]);
        }
        printf("\n");
    }

    return 0;
}

