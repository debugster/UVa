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

    int n, i, j, k;
    ll v, _max;
    vector<ll>data;
    bool found;

    while (cin >> n) {
        if (!n) {
            break;
        }

        data.clear();
        for (i = 1; i <= n; i++) {
            cin >> v;
            data.push_back(v);
        }

        sort(data.begin(), data.end());

        found = false;
        _max = -536870912 * 4;
        for (i = 0; i <= n - 3; i++) {
            for (j = i + 1; j <= n - 2; j++) {
                for (k = j + 1; k < n; k++) {
                    v = data[i] + data[j] + data[k];

                    if (data[i] != data[j] && data[j] != data[k] && data[i] != v && data[j] != v && data[k] != v) {

                        if (binary_search(data.begin(), data.end(), v)) {
                            found = true;
                            _max = max(_max, v);
                        }
                    }
                }
            }
        }

        if (found) {
            cout << _max << "\n";
        }
        else {
            cout << "no solution\n";
        }
    }

    return 0;
}


