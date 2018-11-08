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
#define MAX_NODE 205
#define MAX_COST 10005

/* macro ends */

int matrix[MAX_NODE][MAX_NODE];
void FW(int nodes);

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

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                matrix[i][j] = -1;
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
            if (matrix[u][v] != -1 && weight < matrix[u][v]) {
                continue;
            }

            matrix[u][v] = matrix[v][u] = weight;
        }

        cin >> s1 >> s2;
        source = hashTable[s1];
        dest = hashTable[s2];

        FW(n);
        printf("Scenario #%d\n%d tons\n\n", test++, matrix[source][dest]);
    }

    return 0;
}

void FW(int nodes)
{
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                matrix[i][j] = max(matrix[i][j], min(matrix[i][k], matrix[k][j]));
                //printf("[%d][%d] = %d\n", i, j, matrix[i][j]);
            }
        }
    }
}
