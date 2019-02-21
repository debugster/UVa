#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 105

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

    int test, m, n, q, r, c, i, j, k, ans, x1, x2, y1, y2;
    char X;
    char matrix[MAX][MAX];
    bool keep;

    cin >> test;
    while (test--) {
        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << "\n";
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        while (q--) {
            cin >> r >> c;
            X = matrix[r][c];

            ans = 1;
            for (keep = true, k = 1; keep; k++) {
                x1 = r - k;
                x2 = r + k;
                y1 = c - k;
                y2 = c + k;

                if (x1 < 0 || x1 >= m || x2 < 0 || x2 >= m || y1 < 0 || y1 >= n || y2 < 0 || y2 >= n) {
                    break;
                }

                for (j = y1; j <= y2 && keep; j++) {
                    if (matrix[x1][j] != X) {
                        keep = false;
                    }
                }

                for (j = y1; j <= y2 && keep; j++) {
                    if (matrix[x2][j] != X) {
                        keep = false;
                    }
                }

                for (i = x1; i <= x2 && keep; i++) {
                    if (matrix[i][y1] != X) {
                        keep = false;
                    }
                }

                for (i = x1; i <= x2 && keep; i++) {
                    if (matrix[i][y2] != X) {
                        keep = false;
                    }
                }

                if (keep) {
                    ans += 2;
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}


