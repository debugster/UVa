#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    char input[1000];
    int stat[26];
    int test, Len, i, countPizza;

    scanf("%d", &test);
    while (test--) {
        scanf("%s", input);
        Len = strlen(input);

        for (i = 0; i < 26; i++) {
            stat[i] = 0;
        }

        for (i = 0; i < Len; i++) {
            stat[(int) input[i] - 'A']++;
        }

        countPizza = 0;
        while (1) {

            if (stat[12] >= 1 && stat[0] >= 3 && stat[17] >= 2 && stat[6] >= 1 && stat[8] >= 1 && stat[19] >= 1) {
                countPizza++;
                stat[12]--;
                stat[0] -= 3;
                stat[17] -= 2;
                stat[6]--;
                stat[8]--;
                stat[19]--;
            }
            else {
                break;
            }
        }
        printf("%d\n", countPizza);
    }
    return 0;
}
