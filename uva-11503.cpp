#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 100005

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
            }
            else {
                parent[x] = y;
                numOfElement[y] += numOfElement[x];
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

    int test, f, a, b, start;
    string strA, strB;
    map<string, int>hashTable;
    DisjointSet tree;

    cin >> test;
    while (test--) {
        cin >> f;

        tree.clearTree();
        tree.setTree(MAX);
        start = 0;
        hashTable.clear();
        while (f--) {
            cin >> strA >> strB;

            if (hashTable.find(strA) == hashTable.end()) {
                hashTable[strA] = start++;
            }
            if (hashTable.find(strB) == hashTable.end()) {
                hashTable[strB] = start++;
            }

            a = hashTable[strA];
            b = hashTable[strB];

            tree.makeUnion(a, b);
            cout << tree.getNumOfElement(a) << "\n";
        }
    }

    return 0;
}

