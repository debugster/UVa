//#include <bits/stdc++.h>
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
#include <ext/pb_ds/assoc_container.hpp>    // PBDS
#include <ext/pb_ds/tree_policy.hpp>        // PBDS

using namespace std;
using namespace __gnu_pbds;                 // PBDS

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS_INT;               // PBDS for int
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> PBDS_LL;    // PBDS for long long

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

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
    }
}

/* function ends */

#define MAX_NODE 105
vector<int> adjList[MAX_NODE];
int adjMatrix[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE];

vector<int> findPath(map<int, int> parent, int start, int end)
{
    vector<int> path;

    path.push_back(end);
    while (path[path.size() - 1] != start) {
        path.push_back(parent[path[path.size() - 1]]);
    }
    
    path.reserve();
    for (int i = 0; i < path.size() - 1; i++) {
        if (adjMatrix[i][i + 1] <= 0) {
            path.clear();
            break;
        }
    }

    return path;
}

vector<int> bfs(int start, int end)
{
    map<int, int> parent;
    vector<int> path;
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        int node = Q.pop();
        visited[node] = true;
        if (node == end) {
            path = findPath(parent, start, end);
        }

        for (auto adjNode : adjList[node]) {
            if (!visited[adjNode]) {
                parent[adjNode] = node;
                Q.push(adjNode);
            }
        }
    }

    return path;
}

void clearData()
{
    for (int i = 0; i < MAX_NODE; i++) {
        visited[i] = false;
        adjList[i].clear();
        for (int j = 0; j < MAX_NODE; j++) {
            adjMatrix[i][j] = -1;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    fastIO;

    int n;
    while (cin >> n) {
        if(!n) {
            break;
        }

        
    }

    return 0;
}
