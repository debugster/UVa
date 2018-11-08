#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX_NODE 205
#define MAX_COST 10005

/* macro ends */

///**
int weightTable[MAX_NODE][MAX_NODE];
vector<pii >adjList[MAX_NODE];
int MSTPrim(int source, int dest, int nodes);
void clearAll();
///**

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, i, j, _hash, weight, u, v, source, dest;
    map<string, int> hashTable;
    string s1, s2;
    //char s1[50], s2[50];
    int test = 1, ans;

    while (true) {
        //scanf("%d%d", &n, &r);
        cin >> n >> r;
        //getchar();
        if (!n && !r) {
            break;
        }

        hashTable.clear();
        clearAll();

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                weightTable[i][j] = -1;
            }
        }

        _hash = 0;
        for (i = 1; i <= r; i++) {
            cin >> s1 >> s2 >> weight;
            //getchar();
            //cout << s1 << " " << s2 << " " << weight << endl;
            if (hashTable.find(s1) == hashTable.end()) {
                hashTable[s1] = _hash++;
            }
            if (hashTable.find(s2) == hashTable.end()) {
                hashTable[s2] = _hash++;
            }

            u = hashTable[s1];
            v = hashTable[s2];

            /// discarding multiple edges with lower cost between 2 fixed nodes
            if (weightTable[u][v] != -1 && weight < weightTable[u][v]) {
                continue;
            }

            weightTable[u][v] = weightTable[v][u] = weight;

            adjList[u].push_back(make_pair(v, weight));
            adjList[v].push_back(make_pair(u, weight));
        }

        cin >> s1 >> s2;
        source = hashTable[s1];
        dest = hashTable[s2];

        /*
        for (i = 0; i < _hash; i++) {
            for (j = 0; j < _hash; j++) {
                if (weightTable[i][j] != -1) {
                    printf("[%d][%d] = %d\n", i, j, weightTable[i][j]);
                }
            }
        }
        */
        ans = MSTPrim(source, dest, n);
        printf("Scenario #%d\n%d tons\n\n", test++, ans);
    }

    return 0;
}

void clearAll()
{
    for (int i = 0; i < MAX_NODE; i++) {
        adjList[i].clear();
    }
}

int MSTPrim(int source, int dest, int nodes)
{
    /// PQ.first -> key
    /// PQ.second -> node number
    priority_queue<pii, vector<pii> > PQ;
    vector<int> key(nodes, -1);
    vector<int> parent(nodes, -1);
    vector<int> inMST(nodes, false);
    int ans = MAX_COST;
    int i;

    key[source] = 0;
    PQ.push(make_pair(0, source));

    while (!PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();

        inMST[u] = true;

        pii x;
        for (i = 0; i < adjList[u].size(); i++) {
            x = adjList[u][i];
            int v = x.first;
            int w = x.second;

            if (!inMST[v] && key[v] < w) {
                key[v] = w;
                PQ.push(make_pair(key[v], v));
                parent[v] = u;
                //ans = min(ans, w);
                //printf("v = %d w = %d ans = %d\n", v, w, ans);
            }
        }

        if (inMST[dest]) {
            break;
        }
    }

    i = dest;
    while (i != source) {
        ans = min(ans, weightTable[i][parent[i]]);
        i = parent[i];
    }

    return ans;
}
