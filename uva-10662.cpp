#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 25
#define INF 1000007

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

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
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

    int t, r, h, i, j, k, v, cost, _min;
    int T[MAX], R[MAX], H[MAX];
    bool TR[MAX][MAX], RH[MAX][MAX], HT[MAX][MAX];
    pair<int, pair<int, int> >ans;

    while (cin >> t >> r >> h) {
        for (i = 0; i < t; i++) {
            cin >> T[i];
            for (j = 0; j < r; j++) {
                cin >> v;
                TR[i][j] = !v;
            }
        }

        for (i = 0; i < r; i++) {
            cin >> R[i];
            for (j = 0; j < h; j++) {
                cin >> v;
                RH[i][j] = !v;
            }
        }

        for (i = 0; i < h; i++) {
            cin >> H[i];
            for (j = 0; j < t; j++) {
                cin >> v;
                HT[i][j] = !v;
            }
        }

        _min = INF;
        for (i = 0; i < t; i++) {
            for (j = 0; j < r; j++) {
                for (k = 0; k < h; k++) {
                    if (TR[i][j] && RH[j][k] && HT[k][i]) {
                        cost = T[i] + R[j] + H[k];
                        if (cost < _min) {
                            _min = cost;
                            ans = make_pair(i, make_pair(j, k));
                        }
                    }
                }
            }
        }

        if (_min == INF) {
            cout << "Don't get married!\n";
        }
        else {
            cout << ans.first << " " << ans.second.first << " " << ans.second.second << ":" << _min << "\n";
        }
    }

    return 0;
}


