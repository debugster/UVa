#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 60
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

    int test, t, r, c, i, j, left, right, minMove, ans;
    char ch;
    bool matrix[MAX][MAX];
    int sum[MAX], maxSum;

    cin >> test;
    for (t = 1; t <= test; t++) {
        cin >> r >> c;

        maxSum = 0;
        for (i = 1; i <= r; i++) {
            sum[i] = 0;
            for (j = 1; j <= c; j++) {
                cin >> ch;
                if (ch == '1') {
                    matrix[i][j] = true;
                    sum[i]++;
                }
                else {
                    matrix[i][j] = false;
                }
            }
            maxSum = max(maxSum, sum[i]);
        }

        ans = -1;
        if (maxSum != c) {
            ans = INF;
            for (j = 1; j <= c; j++) {
                minMove = 0;
                for (i = 1; i <= r; i++) {
                    if (matrix[i][j]) {
                        for (left = j - 1; left > 0; left--) {
                            if (!matrix[i][left]) {
                                break;
                            }
                        }

                        if (left <= 0) {
                            left = c;
                        }
                        else {
                            left = j - left;
                        }

                        for (right = j + 1; right <= c; right++) {
                            if (!matrix[i][right]) {
                                break;
                            }
                        }

                        if (right > c) {
                            right = c;
                        }
                        else {
                            right = right - j;
                        }

                        minMove += min(left, right);
                        //cout << "minMove (" << i << ", " << j << "): " << minMove << "\n";
                    }
                }

                ans = min(ans, minMove);
            }
        }

        cout << "Case " << t << ": " << ans << "\n";
    }

    return 0;
}


