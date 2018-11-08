#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

struct TEAM
{
    string name;
    string nameInSmallLetter;
    int gamePlayed;
    int point;
    int win;
    int lose;
    int tied;
    int goalScored;
    int goalReceived;
    int goalDiff;

    TEAM(string n)
    {
        name = nameInSmallLetter = n;
        for (int i = 0; i < nameInSmallLetter.size(); i++) {
            nameInSmallLetter[i] = tolower(nameInSmallLetter[i]);
        }
        gamePlayed = point = win = lose = tied = goalScored = goalReceived = goalDiff = 0;
    }

    bool operator<(const TEAM &T)
    {
        if (point == T.point) {
            if (win == T.win) {
                if (goalDiff == T.goalDiff) {
                    if (goalScored == T.goalScored) {
                        if (gamePlayed == T.gamePlayed) {
                            return nameInSmallLetter < T.nameInSmallLetter;
                        }
                        return gamePlayed < T.gamePlayed;
                    }
                    return goalScored > T.goalScored;
                }
                return goalDiff > T.goalDiff;
            }
            return win > T.win;
        }
        return point > T.point;
    }
};

vector<TEAM>all;
map<string, int>hashTable;

/// n1 -> winner
/// n2 -> loser
void win(int n1, int n2, int goal1, int goal2)
{
    all[n1].gamePlayed++;
    all[n1].point += 3;
    all[n1].win++;
    all[n1].goalScored += goal1;
    all[n1].goalReceived += goal2;
    all[n1].goalDiff += goal1 - goal2;

    all[n2].gamePlayed++;
    all[n2].lose++;
    all[n2].goalScored += goal2;
    all[n2].goalReceived += goal1;
    all[n2].goalDiff += goal2 - goal1;
}

void tie(int n1, int n2, int goal1, int goal2)
{
    all[n1].gamePlayed++;
    all[n1].point++;
    all[n1].tied++;
    all[n1].goalScored += goal1;
    all[n1].goalReceived += goal2;
    all[n1].goalDiff += goal1 - goal2;

    all[n2].gamePlayed++;
    all[n2].point++;
    all[n2].tied++;
    all[n2].goalScored += goal2;
    all[n2].goalReceived += goal1;
    all[n2].goalDiff += goal2 - goal1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, i, start, team, teamCount, game, gameCount, goal1, goal2, n1, n2;
    char ch, tName[105], str1[40], str2[40];
    string teamName1, teamName2;

    scanf("%d", &test);
    getchar();
    for (t = 1; t <= test; t++) {
        gets(tName); /// tournament name
        scanf("%d", &team);
        getchar();

        all.clear();
        hashTable.clear();
        start = 0;
        for (teamCount = 1; teamCount <= team; teamCount++) {
            gets(str1);
            teamName1 = str1;
            hashTable[teamName1] = start++;
            all.push_back(TEAM(teamName1));
        }

        scanf("%d", &game);
        getchar();
        for (gameCount = 1; gameCount <= game; gameCount++) {
            start = 0;
            while ((ch = getchar()) != '#') {
                str1[start++] = ch;
            }
            str1[start] = '\0';
            scanf("%d@%d#", &goal1, &goal2);
            gets(str2);

            //printf("%s %d : %d %s\n", str1, goal1, goal2, str2);

            teamName1 = str1;
            teamName2 = str2;

            n1 = hashTable[teamName1];
            n2 = hashTable[teamName2];

            /// team 1 wins
            if (goal1 > goal2) {
                win(n1, n2, goal1, goal2);
            }
            /// team 2 wins
            else if (goal1 < goal2) {
                win(n2, n1, goal2, goal1);
            }
            /// tie
            else {
                tie(n1, n2, goal1, goal2);
            }
        }

        sort(all.begin(), all.end());

        if (t != 1) {
            printf("\n");
        }

        printf("%s\n", tName);
        for (i = 0; i < team; i++) {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, all[i].name.c_str(), all[i].point, all[i].gamePlayed, all[i].win, all[i].tied, all[i].lose, all[i].goalDiff, all[i].goalScored, all[i].goalReceived);
        }
    }

    return 0;
}
