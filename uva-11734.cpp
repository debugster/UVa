#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, Len, i, j;
    char team[30], teamWS[30], judge[30], dump;

    scanf("%d", &test);
    dump = getchar();
    for (t = 1; t <= test; t++) {
        gets(team);
        //scanf("%s", judge);
        gets(judge);

        printf("Case %d: ", t);

        if (!strcmp(team, judge)) {
            printf("Yes\n");
        }
        else {
            Len = strlen(team);
            for (i = 0, j = 0; i < Len; i++) {
                if (team[i] != ' ') {
                    teamWS[j++] = team[i];
                }
            }
            teamWS[j] = '\0';

            if (!strcmp(teamWS, judge)) {
                printf("Output Format Error\n");
            }
            else {
                printf("Wrong Answer\n");
            }
        }
    }
    return 0;
}
