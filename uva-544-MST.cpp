#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>
// #include <ext/pb_ds/assoc_container.hpp>    // PBDS
// #include <ext/pb_ds/tree_policy.hpp>        // PBDS

using namespace std;
// using namespace __gnu_pbds;                 // PBDS

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS_INT;               // PBDS for int
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> PBDS_LL;    // PBDS for long long

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

#define value_at_index(x) find_by_order(x)
#define index_of(x) order_of_key(x)
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

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
