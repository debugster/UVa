#include <bits/stdc++.h>

using namespace std;

vector<vector<int> >adj;
int dist[21];
bool visited[21];

void BFS(int source, int dest);
void Initialize();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, j, u, v, n, test = 1;;

    while (scanf("%d", &u) != EOF) {
        adj.assign(21, vector<int>());

        for (j = 1; j <= u; j++) {
            scanf("%d", &v);
            adj[1].push_back(v);
            adj[v].push_back(1);
        }

        for (i = 2; i <= 19; i++) {
            scanf("%d", &u);

            for (j = 1; j <= u; j++) {
                scanf("%d", &v);
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }

        printf("Test Set #%d\n", test++);

        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &u, &v);
            BFS(u, v);
            printf("%2d to %2d: %d\n", u, v, dist[v]);
        }

        printf("\n");
    }
    return 0;
}

void Initialize()
{
    for (int i = 1; i <= 20; i++) {
        dist[i] = 0;
        visited[i] = false;
    }
}

void BFS(int source, int dest)
{
    Initialize();

    visited[source] = true;
    queue<int>Q;
    Q.push(source);

    int i, u, v;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        for (i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];

            if (visited[v] == false) {
                visited[v] = true;
                dist[v] = dist[u] + 1;

                Q.push(v);

                if (v == dest) return;
            }
        }
    }
}
