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
#define MAX_NODE 1000
#define INF 10000000

/* macro ends */

struct node
{
    int x; /// x co-ordinate
    int y; /// y co-ordinate
    int cost;
};

struct compare
{
    bool operator()(node &a, node &b)
    {
        return a.cost > b.cost;
    }
};

int moveX[] = {1, -1, 0, 0}; /// Direction array
int moveY[] = {0, 0, 1, -1}; /// Direction array

int cost[MAX_NODE][MAX_NODE];
int dist[MAX_NODE][MAX_NODE];
int row, col;

void initialize(int row, int col);
void Dijkstra2D(node source);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, i, j;
    node source;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &row, &col);

        initialize(row, col);

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                scanf("%d", &cost[i][j]);
            }
        }

        source.x = source.y = 0;
        source.cost = cost[0][0];
        Dijkstra2D(source);
        printf("%d\n", dist[row - 1][col - 1]);
    }

    return 0;
}

void initialize(int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            dist[i][j] = cost[i][j] = INF;
        }
    }
}

void Dijkstra2D(node source)
{
    int i, tempDist;
    priority_queue<node, vector<node>, compare> PQ;
    node u, v;
    u = source;
    PQ.push(u);
    dist[u.x][u.y] = source.cost;

    while (!PQ.empty()) {
        u = PQ.top();
        PQ.pop();

        for (i = 0; i < 4; i++) { /// using direction array to determine next move
            v.x = u.x + moveX[i];
            v.y = u.y + moveY[i];

            if (v.x >= 0 && v.x < row && v.y >= 0 && v.y < col) {
                tempDist = dist[u.x][u.y] + cost[v.x][v.y];
                if (dist[v.x][v.y] > tempDist) {
                    dist[v.x][v.y] = tempDist;
                    v.cost = tempDist;
                    PQ.push(v);
                }
            }
        }
    }
}
