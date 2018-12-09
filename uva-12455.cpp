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
bool generateAllSubset(vector<dataType> &data, dataType sum)
{
    int i, j, n, temp;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        temp = 0;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                //cout << data[j] << " ";
                temp += data[j];
            }
        }
        //cout << "\n";
        if (temp == sum) {
            return true;
        }
    }

    return false;
}

/* function ends */

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, p, i, v, sum;
    vector<int>all;

    cin >> test;
    while (test--) {
        cin >> n >> p;
        all.clear();
        while (p--) {
            cin >> v;
            all.push_back(v);
        }

        if (generateAllSubset(all, n)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}


