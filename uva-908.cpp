#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii; /// first -> key, second -> node

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX_NODE 10005
#define INF 0X7FFFFFFF

/* macro ends */

struct compare
{
    bool operator()(pii &a, pii &b)
    {
        return a.first > b.first;
    }
};

int weightMatrix[MAX_NODE][MAX_NODE];
int MSTPrim(int source, int nodes);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    int n, i, j, k, m, u, v, w;
    int previousTotal, newTotal;

    while (scanf("%d", &n) != EOF) {
        previousTotal = 0;
        for (i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            previousTotal += w;
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                /*
                if (i == j) {
                    weightMatrix[i][j] = 0;
                    continue;
                }
                */
                weightMatrix[i][j] = INF;
            }
        }

        scanf("%d", &k);
        for (i = 1; i <= k; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (weightMatrix[u][v] > w) {
                weightMatrix[u][v] = weightMatrix[v][u] = w;
            }
        }

        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (weightMatrix[u][v] > w) {
                weightMatrix[u][v] = weightMatrix[v][u] = w;
            }
        }

        newTotal = MSTPrim(1, n);
        if (test != 1) {
            printf("\n");
        }
        printf("%d\n%d\n", previousTotal, newTotal);
        test++;
    }

    return 0;
}

int MSTPrim(int source, int nodes)
{
    priority_queue<pii, vector<pii>, compare> PQ;
    vector<int> key(nodes + 1, INF);
    vector<bool> inMST(nodes + 1, false);
    int u, v, w, ans = 0;

    key[source] = 0;
    PQ.push(make_pair(key[source], source));

    while (!PQ.empty()) {
        u = PQ.top().second;
        inMST[u] = true;
        PQ.pop();

        for (v = 1; v <= nodes; v++) {
            w = weightMatrix[u][v];
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                PQ.push(make_pair(key[v], v));
            }
        }
    }

    for (u = 1; u <= nodes; u++) {
        ans += key[u];
    }

    return ans;
}
