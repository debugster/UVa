#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define NOT_IN_THE_GRAPH -1
#define HAS_NO_EDGE 0
#define HAS_MIN_ONE_EDGE 1

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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, i, j, countNode, countEdge, k, tree, acorn;
    char ch, u, v;
    string str;
    stringstream ss;
    int node[26];
    bool graph[26][26];

    cin >> test;
    while (test--) {

        countEdge = 0;
        for (i = 0; i < 26; i++) {
            node[i] = NOT_IN_THE_GRAPH;
            for (j = 0; j < 26; j++) {
                graph[i][j] = false;
            }
        }

        while (cin >> str) {

            if (str[0] == '*') {
                break;
            }

            ss.clear();
            ss.str(str);
            while (ss >> ch >> u >> ch >> v >> ch) {
                if (!graph[u - 'A'][v - 'A'] && u != v) {
                    graph[u - 'A'][v - 'A'] = graph[v - 'A'][u - 'A'] = true;
                    node[u - 'A'] = HAS_MIN_ONE_EDGE;
                    node[v - 'A'] = HAS_MIN_ONE_EDGE;
                    countEdge++;
                }
            }
        }

        getline(cin, str);
        getline(cin, str);
        k = 0;

        if (str != "") {
            ss.clear();
            ss.str(str);

            while (ss >> ch) {
                if (ch >= 'A' && ch <= 'Z') {
                    k++;
                    if (node[ch - 'A'] == NOT_IN_THE_GRAPH) {
                        node[ch - 'A'] = HAS_NO_EDGE;
                    }
                }
            }
        }

        countNode = 0;
        for (i = 0; i < 26; i++) {
            if (node[i] == HAS_MIN_ONE_EDGE) {
                countNode++;
            }
        }

        tree = abs(countEdge - countNode);
        acorn = k - countNode;
        //cout << k << "\n";

        cout << "There are " << tree << " tree(s) and " << acorn  << " acorn(s).\n";
    }

    return 0;
}


