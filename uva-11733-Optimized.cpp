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
#define MAX_NODE 10005
#define INF 10000000

/* macro ends */

struct EDGE
{
    int u;
    int v;
    int cost;

    EDGE()
    {
        u = v = cost = 0;
    }

    EDGE(int x, int y, int c)
    {
        u = x;
        v = y;
        cost = c;
    }

    bool operator<(const EDGE &a) const
    {
        return cost < a.cost;
    }
};

vector<int>adjList[MAX_NODE];
int parent[MAX_NODE];
vector<EDGE>allEdge;
bool visited[MAX_NODE];

void initialize(int nodes);
int findParent(int n);
int mstKruskal(int nodes, int costForAir, int &estimateAirPort);
void BFS(int source);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, m, a, i, x, y, c;
    int pathCost, totalCost, subGraph;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d%d", &n, &m, &a);

        initialize(n);
        for (i = 1; i <= m; i++) {
            scanf("%d%d%d", &x, &y, &c);

            x--; /// because node count starts from 0
            y--;
            adjList[x].push_back(y);
            adjList[y].push_back(x);

            allEdge.push_back(EDGE(x, y, c));
        }

        subGraph = 0;
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                BFS(i);
                subGraph++;
            }
        }
        pathCost = mstKruskal(n, a, subGraph);
        totalCost = pathCost + (subGraph * a);

        printf("Case #%d: %d %d\n", t, totalCost, subGraph);
    }

    return 0;
}

void initialize(int nodes)
{
    allEdge.clear();
    for (int i = 0; i < nodes; i++) {

        adjList[i].clear();
        visited[i] = false;
        parent[i] = i;
    }
}

int findParent(int n)
{
    if (parent[n] == n) {
        return n;
    }

    parent[n] = findParent(parent[n]);
    return parent[n];
}

int mstKruskal(int nodes, int costForAir, int &estimateAirPort)
{
    int _count, a, b, pA, pB, minCost;
    EDGE e;

    sort(allEdge.begin(), allEdge.end());
    _count = minCost = 0;
    for (int i = 0; i < allEdge.size(); i++) {
        e = allEdge[i];
        a = e.u;
        b = e.v;

        pA = findParent(a);
        pB = findParent(b);

        if (pA != pB) {
            parent[pB] = pA;
            _count++;

            /// if airway cost is cheaper than or equal to road cost,
            /// then an airport should be built instead of road
            if (costForAir <= e.cost) {
                estimateAirPort++;
            }
            else {
                minCost += e.cost;
            }
        }

        if (_count == nodes - 1) {
            break;
        }
    }

    return minCost;
}

void BFS(int source)
{
    queue<int>PQ;
    int u, v, i;

    visited[source] = true;
    PQ.push(source);

    while (!PQ.empty()) {
        u = PQ.front();
        PQ.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            v = adjList[u][i];
            if (!visited[v]) {
                visited[v] = true;
                PQ.push(v);
            }
        }
    }
}


