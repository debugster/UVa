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

struct TRIPLE
{
    int a;
    int b;
    int c;

    TRIPLE(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }

    bool operator<(const TRIPLE &t)
    {
        if (a == t.a) {
            if (b == t.b) {
                return c < t.c;
            }
            return b < t.b;
        }
        return a < t.a;
    }
};

int matrix[MAX][MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, j, k;
    string str1, str2, str3, _max;
    vector<TRIPLE>ans;
    set<string>mySet;

    while (cin >> n) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cin >> matrix[i][j];
            }
        }

        ans.clear();
        mySet.clear();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (!matrix[i][j] || i == j) {
                    continue;
                }
                for (k = 1; k <= n; k++) {
                    if (!matrix[j][k] || j == k) {
                        continue;
                    }

                    if (matrix[k][i] && k != i) {
                        str1 = to_string(i) + "-" + to_string(j) + "-" + to_string(k);
                        str2 = to_string(j) + "-" + to_string(k) + "-" + to_string(i);
                        str3 = to_string(k) + "-" + to_string(i) + "-" + to_string(j);

                        //cout << i  << "->" << j << "->" << k << "\n";
                        //cout << "### " << str1 << " " << str2 << " " << str3 << "\n";

                        if (mySet.find(str1) == mySet.end() && mySet.find(str2) == mySet.end() && mySet.find(str3) == mySet.end()) {
                            mySet.insert(str1);
                            mySet.insert(str2);
                            mySet.insert(str3);

                            if (i < j && j < k || i > j && j > k) {
                                ans.push_back(TRIPLE(i, j, k));
                            }
                            else if (j < k && k < i || j > k && k > i) {
                                ans.push_back(TRIPLE(j, k, i));
                            }
                            else {
                                ans.push_back(TRIPLE(k, i, j));
                            }
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        for (i = 0; i < ans.size(); i++) {
            cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << "\n";
        }
        cout << "total:" << ans.size() << "\n\n";
    }

    return 0;
}


