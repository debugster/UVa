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

struct JOB
{
    int serial;
    int priority;

    JOB()
    {
        /// dummy
    }

    JOB(int s, int p)
    {
        serial = s;
        priority = p;
    }

    bool operator()(const JOB &j1, const JOB &j2)
    {
        return j1.priority < j2.priority;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, m, i, p, _count;
    JOB topPQ, topQ;
    priority_queue<JOB, vector<JOB>, JOB>PQ;
    queue<JOB>Q;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &m);

        while (!PQ.empty()) {
            PQ.pop();
        }
        while (!Q.empty()) {
            Q.pop();
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &p);
            Q.push(JOB(i, p));
            PQ.push(JOB(i, p));
        }

        _count = 0;
        while (true) {
            topPQ = PQ.top();
            topQ = Q.front();

            if (topQ.priority < topPQ.priority) {
                Q.pop();
                Q.push(topQ);
                continue;
            }
            else {
                _count++;
                PQ.pop();
                Q.pop();
            }

            if (topQ.serial == m) {
                break;
            }
        }
        printf("%d\n", _count);
    }

    return 0;
}

