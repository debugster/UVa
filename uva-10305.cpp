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
#define MAX_NODE 105

/* macro ends */

vector<int>adjList[MAX_NODE];
int inDegree[MAX_NODE];
vector<int>order;
bool done[MAX_NODE];

void initialize(int nodes);
void TopSort(int nodes);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, u, v;

    while (scanf("%d%d", &n, &m)) {
        if (!n && !m) {
            break;
        }

        initialize(n);
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            adjList[u].push_back(v);
            inDegree[v]++;
        }

        TopSort(n);
        for (i = 0; i < order.size() - 1; i++) {
            printf("%d ", order[i]);
        }
        printf("%d\n", order[i]);
    }

    return 0;
}

void initialize(int nodes)
{
    order.clear();
    for (int i = 1; i <= nodes; i++) {
        adjList[i].clear();
        inDegree[i] = 0;
        done[i] = false;
    }
}

void TopSort(int nodes)
{
    int _count = 0;
    int d, i, v;

    while (_count != nodes) {
        for (i = 1; i <= nodes; i++) {
            if (inDegree[i] == 0 && !done[i]) {
                d = i;
                break;
            }
        }

        for (i = 0; i < adjList[d].size(); i++) {
            v = adjList[d][i];
            inDegree[v]--;
        }

        order.push_back(d);
        done[d] = true;
        _count++;
    }
}
