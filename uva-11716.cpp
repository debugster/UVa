#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, j, Len, sqrtLen;
    char text[10001], dump;

    scanf("%d", &test);
    dump = getchar();
    while (test--) {
        gets(text);

        Len = strlen(text);

        sqrtLen = sqrt(Len);
        if (sqrtLen * sqrtLen == Len) {
            for (i = 0; i < sqrtLen; i++) {
                for (j = i; j < Len; j += sqrtLen) {
                    printf("%c", text[j]);
                }
            }
            printf("\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    return 0;
}
