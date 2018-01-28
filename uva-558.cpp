#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 1000
#define MAX_EDGE 2000
#define INF 1000000

struct EDGE
{
    int u;
    int v;
    int cost;
};

int numberOfNodes;
int numberOfEdges;
int sourceNode;

int dist[MAX_NODE];
EDGE Graph[MAX_EDGE];

bool BellmanFord(); /// returns true if negative cycle exists, false otherwise

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, n, m, i;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &m);

        numberOfNodes = n;
        numberOfEdges = m;

        for (i = 0; i < numberOfEdges; i++) {
            scanf("%d%d%d", &Graph[i].u, &Graph[i].v, &Graph[i].cost);
        }

        sourceNode = 0;

        printf("%s\n", BellmanFord() ? "possible" : "not possible");
    }

    return 0;
}

bool BellmanFord()
{
    int i, j, u, v, c;

    for (i = 0; i < numberOfNodes; i++) {
        dist[i] = INF;
    }

    dist[sourceNode] = 0;

    for (i = 1; i < numberOfNodes; i++) {
        for (j = 0; j < numberOfEdges; j++) {
            u = Graph[j].u;
            v = Graph[j].v;
            c = Graph[j].cost; /// cost for u to v
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
            }
        }
    }

    for (j = 0; j < numberOfEdges; j++) {
        u = Graph[j].u;
        v = Graph[j].v;
        c = Graph[j].cost; /// cost for u to v
        if (dist[u] + c < dist[v]) {
            return true;
        }
    }

    return false;
}
