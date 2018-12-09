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

class UnionFind
{
    vector<int>parent;
    vector<int>_rank;
public:
    UnionFind(int nodes)
    {
        parent.assign(nodes, 0);
        _rank.assign(nodes, 0);

        for (int i = 0; i < nodes; i++) {
            parent[i] = i;
        }
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
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, u, v, suc, unsuc;
    char ch;
    string str;
    stringstream ss;

    cin >> test;
    for (t = 1; t <= test; t++) {
        cin >> n;
        cin.ignore();
        UnionFind tree(n);
        suc = unsuc = 0;
        while (getline(cin, str)) {

            if (str == "") {
                break;
            }

            //cout << str << "\n";

            ss.clear();
            ss.str(str);
            ss >> ch >> u >> v;
            if (ch == 'c') {
                tree.makeUnion(u - 1, v - 1);
            }
            else {
                if (tree.isSameSet(u - 1, v - 1)) {
                    suc++;
                }
                else {
                    unsuc++;
                }
            }
        }

        if (t != 1) {
            cout << "\n";
        }
        cout << suc << "," << unsuc << "\n";
    }

    return 0;
}



