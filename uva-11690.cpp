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

public:
    set<int>whoAreParent;
    vector<int>netAmount; /// calculates the net amount of money in a subtree;

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
        netAmount.assign(nodes, 0);

        for (int i = 0; i < nodes; i++) {
            parent[i] = i;
            whoAreParent.insert(i);
        }
    }

    void clearTree()
    {
        parent.clear();
        _rank.clear();
        numOfSet = 0;
        numOfElement.clear();
        whoAreParent.clear();
        netAmount.clear();
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
                //whoAreParent.erase(whoAreParent.find(y));
                whoAreParent.erase(y);
                netAmount[x] += netAmount[y];
            }
            else {
                parent[x] = y;
                numOfElement[y] += numOfElement[x];
                //whoAreParent.erase(whoAreParent.find(x));
                whoAreParent.erase(x);
                netAmount[y] += netAmount[x];
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
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, m, i, x, y;
    DisjointSet tree;
    set<int>::iterator it;
    bool yes;

    cin >> test;
    while (test--) {
        cin >> n >> m;

        tree.clearTree();
        tree.setTree(n);
        for (i = 0; i < n; i++) {
            cin >> tree.netAmount[i];
        }

        while (m--) {
            cin >> x >> y;
            tree.makeUnion(x , y);
        }

        yes = true;
        for (it = tree.whoAreParent.begin(); it != tree.whoAreParent.end(); it++) {
            if (tree.netAmount[*it] != 0) {
                yes = false;
                break;
            }
        }

        if (yes) {
            cout << "POSSIBLE\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}



