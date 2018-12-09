#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

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

class DisjointSet
{
    vector<int>parent;
    vector<int>_rank;
    int numOfSet; /// counts the number of disjoint sets in the tree

public:
    DisjointSet()
    {
        /// empty
    }

    DisjointSet(int nodes)
    {
        setTree(nodes);
    }

    void setTree(int nodes)
    {
        parent.assign(nodes, 0);
        _rank.assign(nodes, 0);
        numOfSet = nodes;

        for (int i = 0; i < nodes; i++) {
            parent[i] = i;
        }
    }

    void clearTree()
    {
        parent.clear();
        _rank.clear();
        numOfSet = 0;
    }

    int findSet(int i) /// find the set representative of node 'i'
    {
        if (parent[i] != i) {
            parent[i] = findSet(parent[i]);
        }
        return parent[i];
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void makeUnion(int i, int j)
    {
        if (!isSameSet(i, j)) {

            numOfSet--; /// two trees have been merged into one, so number of trees decreases by one

            int x = findSet(i);
            int y = findSet(j);

            if (_rank[x] > _rank[y]) { /// ranks keeps the tree short
                parent[y] = x;
            }
            else {
                parent[x] = y;
            }

            if (_rank[x] == _rank[y]) {
                _rank[y]++;
            }
        }
    }

    int getNumOfSet()
    {
        return numOfSet;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, n, m, i, j;
    DisjointSet tree;

    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }

        tree.clearTree();
        tree.setTree(n);

        while (m--) {
            cin >> i >> j;
            tree.makeUnion(i - 1, j - 1);
        }

        cout << "Case " << t++ << ": " << tree.getNumOfSet() << "\n";
    }

    return 0;
}
