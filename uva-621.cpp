#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, Len;
    char text[100001];

    scanf("%d", &test);
    while (test--) {
        scanf("%s", text);
        Len = strlen(text);

        if (!strcmp(text, "1") || !strcmp(text, "4") || !strcmp(text, "78")) {
            printf("+\n");
        }
        else {
            if (text[Len - 2] == '3' && text[Len - 1] == '5') {
                printf("-\n");
            }
            else if (text[0] == '9' && text[Len - 1] == '4') {
                printf("*\n");
            }
            else {
                printf("?\n");
            }
        }
    }
    return 0;
}
