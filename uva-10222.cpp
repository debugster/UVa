#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /// 128 bit ASCII Table
    char MAP[] = "                                 !l    l    n m,          kkn m,  czaqsdfyghjbvui w etx  r o;p    czaqsdfyghjbvui w etx  r o;p  ";
    char text[100002];
    int i, Len;

    while (gets(text)) {
        Len = strlen(text);

        for (i = 0; i < Len; i++) {
            printf("%c", MAP[text[i]]);
        }
        printf("\n");
    }
    return 0;
}
