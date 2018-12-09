#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX_NODE 30005

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// extracts numbers from a string and pushes into vector
template<typename dataType>
void extractNumberFromString(string str, vector<dataType> &v)
{
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    dataType found;
    v.clear();
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) {
            //cout << found << " " << sizeof(found) << "\n";
            v.push_back(found);
        }

        /* To save from space at the end of string */
        temp = "";
    }
}

/* function ends */

vector<int>adjList[MAX_NODE];
bool visited[MAX_NODE];
int infected;

void DFS(int u);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, k, u, v;

    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }

        for (i = 0; i < n; i++) {
            adjList[i].clear();
            visited[i] = false;
        }

        while (m--) {
            cin >> k >> u;
            k--;
            while (k--) {
                cin >> v;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        infected = 0;
        DFS(0);
        cout << infected << "\n";
    }

    return 0;
}

void DFS(int u)
{
    visited[u] = true;
    infected++;

    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}
