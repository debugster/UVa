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
    double percentage;

    TEAM(string n)
    {
        name = nameInSmallLetter = n;
        for (int i = 0; i < nameInSmallLetter.size(); i++) {
            nameInSmallLetter[i] = tolower(nameInSmallLetter[i]);
        }
        gamePlayed = point = win = lose = tied = goalScored = goalReceived = goalDiff = 0;
        percentage = -1.0;
    }

    bool operator<(const TEAM &T)
    {
        if (point == T.point) {
            if (goalDiff == T.goalDiff) {
                if (goalScored == T.goalScored) {
                    return nameInSmallLetter < T.nameInSmallLetter;
                }
                return goalScored > T.goalScored;
            }
            return goalDiff > T.goalDiff;
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

    int test = 1, t, g, i, g1, g2, n1, n2, _rank;
    char str1[100], str2[100];
    string team1, team2;

    while (scanf("%d%d", &t, &g)) {
        //getchar();
        if (!t && !g) {
            break;
        }

        all.clear();
        hashTable.clear();

        all.push_back(TEAM(string("DUMMY TEAM")));
        for (i = 1; i <= t; i++) {
            //gets(str1);
            scanf("%s", str1);
            team1 = str1;
            hashTable[team1] = i;
            all.push_back(TEAM(team1));
        }

        for (i = 1; i <= g; i++) {
            scanf("%s %d - %d %s", str1, &g1, &g2, str2);
            team1 = str1;
            team2 = str2;

            n1 = hashTable[team1];
            n2 = hashTable[team2];

            if (g1 > g2) {
                win(n1, n2, g1, g2);
            }
            else if (g1 < g2) {
                win(n2, n1, g2, g1);
            }
            else {
                tie(n1, n2, g1, g2);
            }
        }

        sort(all.begin() + 1, all.end());

        if (test != 1) {
            printf("\n");
        }
        test++;

        all[0] = all[1];
        _rank = 1;
        printf("%2d. ", _rank);
        for (i = 1; i <= t; i++) {
            if (all[i].point == all[i - 1].point && all[i].goalDiff == all[i - 1].goalDiff && all[i].goalScored == all[i - 1].goalScored) {
                /// do not print the rank again
                if (i > 1) {
                    printf("    ");
                }
            }
            else {
                _rank = i;
                printf("%2d. ", _rank);
            }

            printf("%15s %3d %3d %3d %3d %3d ", all[i].name.c_str(), all[i].point, all[i].gamePlayed, all[i].goalScored, all[i].goalReceived, all[i].goalDiff);

            if (all[i].gamePlayed == 0) {
                printf("   N/A\n");
            }
            else {
                all[i].percentage = (all[i].point * 100.0) / (all[i].gamePlayed * 3);
                printf("%6.2lf\n", all[i].percentage);
            }
        }
    }

    return 0;
}

