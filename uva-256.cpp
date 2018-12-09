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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //vector<ll>two, four, six, eight;
    vector<ll>all[9];
    ll i, j, k;

    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            k = (i * 10) + j;
            if ((i + j) * (i + j) == k) {
                all[2].push_back(k);
            }
        }
    }

    for (i = 0; i <= 99; i++) {
        for (j = 0; j <= 99; j++) {
            k = (i * 100) + j;
            if ((i + j) * (i + j) == k) {
                all[4].push_back(k);
            }
        }
    }

    for (i = 0; i <= 999; i++) {
        for (j = 0; j <= 999; j++) {
            k = (i * 1000) + j;
            if ((i + j) * (i + j) == k) {
                all[6].push_back(k);
            }
        }
    }

    for (i = 0; i <= 9999; i++) {
        for (j = 0; j <= 9999; j++) {
            k = (i * 10000) + j;
            if ((i + j) * (i + j) == k) {
                all[8].push_back(k);
            }
        }
    }

    while (cin >> k) {
        for (int i = 0; i < all[k].size(); i++) {
            cout << setw(k) << setfill('0') << all[k][i] << "\n";
        }
    }

    return 0;
}


