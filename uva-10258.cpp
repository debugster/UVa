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
#define MAX 101
#define MAX_P 11

/* macro ends */

struct LOG
{
    int teamNo;
    int problemNo;
    int mm;
    char verdict;

    LOG(int t, int p, int m, char v)
    {
        teamNo = t;
        problemNo = p;
        mm = m;
        verdict = v;
    }

    bool operator<(const LOG &l)
    {

        /*
        if (mm == l.mm) {
            if (verdict == l.verdict) {
                return teamNo < l.teamNo;
            }
            return verdict <= l.verdict;
        }
        */
        return mm < l.mm;
    }
};

struct TEAM
{
    int teamNumber;
    int solvedCount;
    int totalTime;
    int solved[MAX_P];
    int tryCount[MAX_P];
    int _rank;
    bool tried; /// tried at least 1 problem

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

        for (int j = 0; j < MAX_P; j++) {
            all[i].solved[j] = all[i].tryCount[j] = 0;
        }

        all[i]._rank = 0;
        all[i].tried = false;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t = 0, i, totalTeam;
    int teamNo, mm, problemNo;
    char verdict, ch;
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

            sscanf(logText, "%d %d %d %c", &teamNo, &problemNo, &mm, &verdict);
            totalTeam = max(totalTeam, teamNo);
            /*
            if (verdict == 'C') {
                verdict = 'Y';
            }
            else if (verdict == 'I') {
                verdict = 'N';
            }
            */
            if (verdict != 'C' && verdict != 'I') {
                verdict = 'X'; /// submission will be ignored
            }
            allLog.push_back(LOG(teamNo, problemNo, mm, verdict));
        }

        //t++;
        if (t != 1) {
            printf("\n");
        }
        //printf("T = %d\n", t);


        sort(allLog.begin(), allLog.end());

        /*
        for (i = 0; i < allLog.size(); i++) {
            sprintf(temp, "%d %d %d %c", allLog[i].teamNo, allLog[i].problemNo, allLog[i].mm, allLog[i].verdict);
            puts(temp);
        }
        */


        for (i = 0; i < allLog.size(); i++) {
            teamNo = allLog[i].teamNo;
            problemNo = allLog[i].problemNo;
            mm = allLog[i].mm;
            verdict = allLog[i].verdict;

            all[teamNo].tried = true;

            if (all[teamNo].solved[problemNo] == 1 || verdict == 'X') {
                continue;
            }
            else if (verdict == 'I' && all[teamNo].solved[problemNo] == -1) {
                all[teamNo].tryCount[problemNo]++;
            }
            else if (verdict == 'I' && all[teamNo].solved[problemNo] == 0) {
                all[teamNo].solved[problemNo] = -1;
                all[teamNo].tryCount[problemNo]++;
            }
            else if (verdict == 'C') {
                all[teamNo].solved[problemNo] = 1;
                all[teamNo].solvedCount++;
                all[teamNo].totalTime += mm + (all[teamNo].tryCount[problemNo] * 20);
                //printf("%d\n", all[teamNo].totalTime);
                //sprintf(temp, "%d %c %d:%02d %c", allLog[i].teamNo, allLog[i].problemNo, allLog[i].hh, allLog[i].mm, allLog[i].verdict);
                //puts(temp);
            }
        }

        sort(all + 1, all + 1 + totalTeam);
        all[0].solvedCount = all[1].solvedCount;
        all[0].totalTime = all[1].totalTime;
        all[0]._rank = 1;


        for (i = 1; i <= totalTeam; i++) {
            if (all[i].tried) {
                printf("%d %d %d\n", all[i].teamNumber, all[i].solvedCount, all[i].totalTime);
            }
        }


        allLog.clear();

        if (t == test) {
            break;
        }

    }

    return 0;
}

