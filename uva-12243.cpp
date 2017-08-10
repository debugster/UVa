#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char Line[2000], first;
    int i, Len;
    bool valid;

    while (gets(Line)) {

        if (!strcmp(Line, "*")) {
            break;
        }

        Len = strlen(Line);
        first = tolower(Line[0]);
        valid = true;
        for (i = 1; i < Len; i++) {
            if (Line[i] == ' ' && tolower(Line[i + 1]) != first) {
                valid = false;
                break;
            }
        }

        if (valid) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }
    return 0;
}
