#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char c[10], dump;
    int test, Len, i, sum;
    scanf("%d", &test);
    dump = getchar();
    while (test--) {
        gets(c);
        Len = strlen(c);
        if (Len == 5) {
            printf("3\n");
        }
        else {
            if ((c[0] == 'o' && c[1] == 'n') || (c[1] == 'n' && c[2] == 'e') || (c[2] == 'e' && c[0] == 'o')) {
                printf("1\n");
            }
            else {
                printf("2\n");
            }
        }
    }
    return 0;
}

