#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

/* function starts */

template<typename dataType>
dataType nthGrayCode(dataType n) /// n is 0-based
{
    return (n ^ (n >> 1));
}

/* function ends */

vector<queue<int> >Q;
vector<queue<int> >Q_copy;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1, t, i, j, k, n, m, tNo, qNo;
    char cmd[20];
    map<int, int>teamNo; /// first = member no, second = team no
    map<int, int>queueNo; /// first = team no, second = queue no
    map<int, int>queueToTeamNo; /// first = queue no, second = team no

    while (scanf("%d", &t)) {
        if (!t) {
            break;
        }

        Q.clear();
        teamNo.clear();
        queueNo.clear();
        queueToTeamNo.clear();

        for (i = 0; i < t; i++) {
            scanf("%d", &n);
            for (j = 1; j <= n; j++) {
                scanf("%d", &m);
                teamNo[m] = i;
            }
        }

        printf("Scenario #%d\n", test++);
        k = 0;
        while (scanf("%s", cmd)) {

            //puts(cmd);

            if (!strcmp(cmd, "STOP")) {
                break;
            }

            if (!strcmp(cmd, "ENQUEUE")) {
                scanf("%d", &m);

                tNo = teamNo[m];
                if (queueNo.find(tNo) == queueNo.end()) {
                    queueNo[tNo] = k;
                    queueToTeamNo[k] = tNo;
                    k++;
                    Q.push_back(queue<int>());
                }
                qNo = queueNo[tNo];
                Q[qNo].push(m);
            }
            else {
                for (i = 0; i < Q.size(); i++) {
                    if (!Q[i].empty()) {
                        m = Q[i].front();
                        Q[i].pop();

                        if (Q[i].empty()) {
                            tNo = queueToTeamNo[i];
                            queueNo.erase(tNo);
                        }

                        break;
                    }
                }
                printf("%d\n", m);
            }

            /*
            Q_copy.clear();
            Q_copy = Q;
            printf("## ");
            for (i = 0; i < Q_copy.size(); i++) {
                while (!Q_copy[i].empty()) {
                    m = Q_copy[i].front();
                    Q_copy[i].pop();
                    printf("%d ", m);
                }
            }
            printf("##\n");
            */

        }
        printf("\n");
    }

    return 0;
}

