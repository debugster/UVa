#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

char x0[MAX + 5];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i;
    char A[100];

    while (scanf("%s", x0)) {
        if (!strcmp(x0, "END")) {
            break;
        }

        i = 1;
        while (true) {
            sprintf(A, "%d", strlen(x0));
            if (!strcmp(x0, A)) {
                break;
            }
            i++;
            strcpy(x0, A);
        }
        printf("%d\n", i);
    }

    return 0;
}

