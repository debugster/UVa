#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX_N 10
#define MAX_M 30

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

bool compare(pii &a, pii &b)
{
    if (a.first == b.first) {
        return a.second <= b.second;
    }
    return a.first < b.first;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, m, i, j, k;
    int matrix[MAX_N][MAX_M];
    int rowSum[MAX_N];
    int columnSum[MAX_M];
    vector<pii>edges; /// for checking multiple edges between 2 distinct nodes
    vector<int>temp;
    bool columnOK; /// every column sum must be == 2
    bool multiEdge;

    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> matrix[i][j];
            }
        }

        edges.clear();
        columnOK = true;
        for (j = 1; j <= m; j++) {
            columnSum[j] = 0;
            temp.clear();
            for (i = 1; i <= n; i++) {
                columnSum[j] += matrix[i][j];

                if (matrix[i][j] == 1) {
                    temp.push_back(i);
                }

            }
            if (columnSum[j] != 2) {
                columnOK = false;
                break;
            }

            edges.push_back(make_pair(temp[0], temp[1]));
        }

        /// check for multiple edges
        sort(edges.begin(), edges.end(), compare);

        multiEdge = false;
        if (columnOK && edges.size() >= 2) {
            for (i = 0; i < edges.size() - 1; i++) {
                if (edges[i].first == edges[i + 1].first && edges[i].second == edges[i + 1].second) {
                    multiEdge = true;
                    break;
                }
            }
        }

        if (columnOK && !multiEdge) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}


