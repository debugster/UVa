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
#define MAX 40
#define MAX_P 40

/* macro ends */

struct LOG
{
    int teamNo;
    char problemNo;
    int hh;
    int mm;
    char verdict;

    LOG(int t, char p, int h, int m, char v)
    {
        teamNo = t;
        problemNo = p;
        hh = h;
        mm = m;
        verdict = v;
    }

    bool operator<(const LOG &l)
    {
        if (hh == l.hh) {
            if (mm == l.mm) {
                if (verdict == l.verdict) {
                    return teamNo < l.teamNo;
                }
                return verdict <= l.verdict;
            }
            return mm < l.mm;
        }
        return hh < l.hh;
    }
};

struct TEAM
{
    int teamNumber;
    int solvedCount;
    int totalTime;
    int solved[MAX_P]; /// A-G, 0 - Not Solved, 1 - Solved, -1 - Tried
    int tryCount[MAX_P];
    int _rank;

    bool operator<(const TEAM &t)
    {
        if (solvedCount == t.solvedCount) {
            if (totalTime == t.totalTime) {
                return teamNumber < t.teamNumber;
            }
            return totalTime < t.totalTime;
        }
        return solvedCount > t.solvedCount;
    }
};

TEAM all[MAX];

void initialize()
{
    for (int i = 1; i < MAX; i++) {
        all[i].teamNumber = i;
        all[i].solvedCount = 0;
        all[i].totalTime = 0;

        for (int j = 0; j < 7; j++) {
            all[i].solved[j] = all[i].tryCount[j] = 0;
        }

        all[i]._rank = 0;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t = 0, i, totalTeam;
    int teamNo, hh, mm;
    char problemNo, verdict, ch;
    char logText[100], temp[100];
    vector<LOG>allLog;

    scanf("%d", &test);
    getchar();
    getchar();

    while (true) {

        initialize();
        totalTeam = 0;

        while (true) {

            ch = getchar();

            if (ch == -1 || ch == '\n') {
                t++;
                break;
            }
            else {
                ungetc(ch, stdin);
            }

            gets(logText);
            //puts(logText);

            sscanf(logText, "%d %c %d:%d %c", &teamNo, &problemNo, &hh, &mm, &verdict);
            totalTeam = max(totalTeam, teamNo);
            allLog.push_back(LOG(teamNo, problemNo, hh, mm, verdict));
        }

        //t++;
        if (t != 1) {
            printf("\n");
        }
        //printf("T = %d\n", t);


        sort(allLog.begin(), allLog.end());

        /*
        for (i = 0; i < allLog.size(); i++) {
            sprintf(temp, "%d %c %d:%02d %c", allLog[i].teamNo, allLog[i].problemNo, allLog[i].hh, allLog[i].mm, allLog[i].verdict);
            puts(temp);
        }
        */


        for (i = 0; i < allLog.size(); i++) {
            teamNo = allLog[i].teamNo;
            problemNo = allLog[i].problemNo;
            hh = allLog[i].hh;
            mm = allLog[i].mm;
            verdict = allLog[i].verdict;

            if (all[teamNo].solved[(int) problemNo - 'A'] == 1) {
                continue;
            }
            else if (verdict == 'N' && all[teamNo].solved[(int) problemNo - 'A'] == -1) {
                all[teamNo].tryCount[(int) problemNo - 'A']++;
            }
            else if (verdict == 'N' && all[teamNo].solved[(int) problemNo - 'A'] == 0) {
                all[teamNo].solved[(int) problemNo - 'A'] = -1;
                all[teamNo].tryCount[(int) problemNo - 'A']++;
            }
            else if (verdict == 'Y') {
                all[teamNo].solved[(int) problemNo - 'A'] = 1;
                all[teamNo].solvedCount++;
                all[teamNo].totalTime += (hh * 60) + mm + (all[teamNo].tryCount[(int) problemNo - 'A'] * 20);
                //printf("%d\n", all[teamNo].totalTime);
                //sprintf(temp, "%d %c %d:%02d %c", allLog[i].teamNo, allLog[i].problemNo, allLog[i].hh, allLog[i].mm, allLog[i].verdict);
                //puts(temp);
            }
        }

        sort(all + 1, all + 1 + totalTeam);
        all[0].solvedCount = all[1].solvedCount;
        all[0].totalTime = all[1].totalTime;
        all[0]._rank = 1;


        printf("RANK TEAM PRO/SOLVED TIME\n");
        for (i = 1; i <= totalTeam; i++) {
            if (all[i].solvedCount == all[i - 1].solvedCount && all[i].totalTime == all[i - 1].totalTime) {
                all[i]._rank = all[i - 1]._rank;
            }
            else {
                all[i]._rank = i;
            }

            //printf("%4d %4d %4d       %4d\n", all[i]._rank, all[i].teamNumber, all[i].solvedCount, all[i].totalTime);
            printf("%4d %4d", all[i]._rank, all[i].teamNumber);
            if (all[i].solvedCount != 0) {
                printf(" %4d       %4d\n", all[i].solvedCount, all[i].totalTime);
            }
            else {
                printf("\n");
            }
        }


        allLog.clear();

        if (t == test) {
            break;
        }

    }

    return 0;
}
