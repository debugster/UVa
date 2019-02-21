#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 1005
#define INF 1000005

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

    int m, i, j, d, minD, ans;
    char c;
    //int matrix[MAX][MAX];
    vector<pii>one, three;

    while (cin >> m) {
        one.clear();
        three.clear();

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= m; j++) {
                //cin >> matrix[i][j];
                cin >> c;
                if (c == '1') {
                    one.push_back(make_pair(i, j));
                }
                else if (c == '3') {
                    three.push_back(make_pair(i, j));;
                }
            }
        }

        ans = 0;
        for (i = 0; i < one.size(); i++) {
            //cout << "1 : (" << one[i].first << ", " << one[i].second << ")\n";

            minD = INF;
            for (j = 0; j < three.size(); j++) {
                //cout << "\t3 : (" << three[j].first << ", " << three[j].second << ")\n";

                d = abs(one[i].first - three[j].first) + abs(one[i].second - three[j].second);
                minD = min(minD, d);
                //cout << "\td: " << d << " minD: " << minD << "\n";
            }
            ans = max(ans, minD);
            //cout << "ans: " << ans << "\n";
        }

        cout << ans << "\n";
    }

    return 0;
}


