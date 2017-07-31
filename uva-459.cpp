#include <bits/stdc++.h>

using namespace std;

int visitRemain;
vector<vector<int> > adj;
bool visited[27];

void BFS(int source);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, nodes, i, u, v, subGraph;
    char maxNode, dump, edge[2];

    scanf("%d", &test);
    dump = getchar(); /// To discard the carriage return after taking input the Test Case number
    dump = getchar(); /// Taking the extra newline as garbage
    while (test--) {
        scanf("%c", &maxNode);
        dump = getchar(); /// To discard the carriage return after taking input the Max Node

        /// We'll convert node values from Alphabetic to Numeric
        /// And allocate N x N matrix where N = Max Node + 1 to index from 1 (not from 0)
        /// If Max Node is E, that means 5 nodes
        /// Then we'll need 6 x 6 matrix
        nodes = (int) maxNode - 'A' + 2;
        adj.assign(nodes, vector<int>());
        while (gets(edge)) {

            if (edge[0] == '\0') break;

            /// converting node values from Alphabetic to Numeric
            u = (int) edge[0] - 'A' + 1;
            v = (int) edge[1] - 'A' + 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        /*
        for (int i = 1; i < nodes; i++) {
            printf("%c -> ", 'A' + i - 1);
            for (int j = 0; j < adj[i].size(); j++) {
                printf("%c ", 'A' + adj[i][j] - 1);
            }
            printf("\n");
        }
        */

        visitRemain = nodes - 1;
        subGraph = 0;
        //printf("%d\n", visitRemain);
        for (i = 1; i <= visitRemain; i++) {
            visited[i] = false;
        }

        for (i = 1; i <= nodes - 1 && visitRemain != 0; i++) {
            if (visited[i] == false) {
                BFS(i);
                subGraph++;
            }
        }

        printf("%d\n", subGraph);
        if (test != 0) printf("\n");
    }
    return 0;
}

void BFS(int source)
{
    visited[source] = true;
    visitRemain--;
    queue<int>Q;
    Q.push(source);

    int u, v, i;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        for (i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];

            if (visited[v] == false) {
                visited[v] = true;
                visitRemain--;
                Q.push(v);
            }
        }
    }
}
