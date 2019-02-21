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

string makeAscendOrder(int a, int b, int c)
{
    string str;
    int _min, _max, _mid, total;

    total = a + b + c;
    _min = min(a, min(b, c));
    _max = max(a, max(b, c));
    _mid = total - _min - _max;

    str = to_string(_min) + " " + to_string(_mid) + " " + to_string(_max);
    return str;
}

int DP[181][2];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, j, k, _count;
    bool allPossibleScore[61];
    string str;
    set<string>combination;

    for (i = 0; i <= 180; i++) {
        for (j = 0; j <= 1; j++) {
            DP[i][j] = -1;
        }
    }

    for (i = 21; i <= 60; i++) {
        allPossibleScore[i] = false;
    }
    for (i = 0; i <= 20; i++) {
        allPossibleScore[i] = true;
        allPossibleScore[i * 2] = true;
        allPossibleScore[i * 3] = true;
    }

    allPossibleScore[50] = true;

    while (cin >> n) {
        if (n <= 0) {
            cout << "END OF OUTPUT\n";
            break;
        }

        if (n > 180) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
            cout << "**********************************************************************\n";
            continue;
        }

        if (DP[n][0] == -1) {
            _count = 0;
            combination.clear();
            for (i = 0; i <= 60; i++) {
                if (!allPossibleScore[i]) {
                    continue;
                }

                for (j = 0; j <= 60; j++) {
                    if (!allPossibleScore[j]) {
                        continue;
                    }

                    for (k = 0; k <= 60; k++) {
                        if (!allPossibleScore[k]) {
                            continue;
                        }

                        if (i + j + k == n) {
                            _count++;

                            //cout << i << " " << j << " " << k << "\n";

                            str = makeAscendOrder(i, j, k);
                            if (combination.find(str) == combination.end()) {
                                combination.insert(str);
                            }
                        }
                    }
                }
            }

            DP[n][0] = combination.size();
            DP[n][1] = _count;
        }

        if (DP[n][0] == 0) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        }
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << DP[n][0] << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << DP[n][1] << ".\n";
        }

        cout << "**********************************************************************\n";
    }

    return 0;
}


