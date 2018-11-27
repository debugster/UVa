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
    vector<int>numOfElement; /// counts the number of member elements in all disjoint subtrees
    int _max;

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
        numOfElement.assign(nodes, 1); /// initially, all disjoint subtrees contains 1 element
        _max = 1;

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
                numOfElement[x] += numOfElement[y];
                _max = max(_max, numOfElement[x]);
            }
            else {
                parent[x] = y;
                numOfElement[y] += numOfElement[x];
                _max = max(_max, numOfElement[y]);
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

    int getNumOfElement(int node)
    {
        return numOfElement[findSet(node)];
    }

    int getMax()
    {
        return _max;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, m, i, a, b;
    DisjointSet tree;
    string strA, strB;
    map<string, int>hashTable;

    while (cin >> n >> m) {

        if (!n && !m) {
            break;
        }

        tree.clearTree();
        tree.setTree(n);
        hashTable.clear();

        for (i = 0; i < n; i++) {
            cin >> strA;
            hashTable[strA] = i;
        }

        while (m--) {
            cin >> strA >> strB;
            a = hashTable[strA];
            b = hashTable[strB];
            tree.makeUnion(a, b);
        }

        cout << tree.getMax() << "\n";
    }

    return 0;
}
