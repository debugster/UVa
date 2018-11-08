#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    bool isPalindrome[24][60], isTrue;
    int nextTimeHour[24][60], nextTimeMinute[24][60];
    int h, m, time, i, j, Limit, LastHour = 0, LastMinute = 0;
    char strTime[5];

    for (h = 23; h >= 0; h--) {
        for (m = 59; m >= 0; m--) {

            time = h * 100 + m;

            sprintf(strTime, "%d", time);
            Limit = strlen(strTime);
            j = Limit - 1;
            Limit = Limit / 2;
            isTrue = true;
            for (i = 0; i < Limit; i++, j--) {
                if (strTime[i] != strTime[j]) {
                    isTrue = false;
                    break;
                }
            }

            isPalindrome[h][m] = isTrue;

            nextTimeHour[h][m] = LastHour;
            nextTimeMinute[h][m] = LastMinute;

            if (isTrue) {
                LastHour = h;
                LastMinute = m;
            }
        }
    }

    /*
    for (h = 0; h < 24; h++) {
        for (m = 0; m < 60; m++) {
            printf("%2d:%2d\t%d\n", h, m, isPalindrome[h][m]);
        }
    }
    */

    int test;

    scanf("%d", &test);
    while (test--) {
        scanf("%d:%d", &h, &m);
        printf("%02d:%02d\n", nextTimeHour[h][m], nextTimeMinute[h][m]);
    }

    return 0;
}
