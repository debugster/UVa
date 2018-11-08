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
#define MAX_NODE 100005

/* macro ends */

int parent[MAX_NODE];
int countParent[MAX_NODE];

void initializer();
void makeUnion(int a, int b);
int findParent(int a);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, edge, i, j, start, u, v, ans;
    map<string, int>hashTable;
    string s1, s2;
    char t1[30], t2[30];

    scanf("%d", &test);
    while (test--) {
        scanf("%d", &edge);

        start = 1;
        hashTable.clear();
        initializer();
        for (i = 1; i <= edge; i++) {
            //cin >> s1 >> s2;
            scanf("%s %s", t1, t2);
            s1 = t1;
            s2 = t2;
            //cout << s1 << " " << s2 << "\n";

            if (hashTable.find(s1) == hashTable.end()) {
                hashTable[s1] = start++;
            }
            if (hashTable.find(s2) == hashTable.end()) {
                hashTable[s2] = start++;
            }

            u = hashTable[s1];
            v = hashTable[s2];

            //printf("u = %d v = %d\n", u, v);

            makeUnion(u, v);
            ans = max(countParent[parent[u]], countParent[parent[v]]);

            /*
            for (j = 1; j <= 26; j++) {
                printf("parent[%d] = %d | countParent[%d] = %d\n", j, parent[j], j, countParent[j]);
            }
            */

            printf("%d\n", ans);
        }
    }

    return 0;
}

void initializer()
{
    for (int i = 1; i < MAX_NODE; i++) {
        parent[i] = i;
        countParent[i] = 1;
    }
}

int findParent(int a)
{
    if (parent[a] == a) {
        return a;
    }
    else {
        int x;
        x = findParent(parent[a]);
        parent[a] = x;
        //countParent[x]++;
        return x;
    }
}

void makeUnion(int a, int b)
{
    int u = findParent(a);
    int v = findParent(b);

    if (u != v) {
        if (countParent[u] >= countParent[v]) {
            parent[v] = u;
            countParent[u] += countParent[v];
        }
        else {
            parent[u] = v;
            countParent[v] += countParent[u];
        }
    }
}
