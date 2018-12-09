#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 1010

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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, p, i, v, _count, _min;
    string line;
    stringstream ss;
    vector<int>ans;

    cin >> test;
    while (test--) {
        cin >> p;
        cin.ignore();
        _min = MAX;
        for (i = 1; i <= p; i++) {
            getline(cin, line);
            //cout << line << "\n";
            ss.clear();
            ss.str(line);
            _count = 0;
            while (ss >> v) {
                _count++;
            }
            if (_count == _min) {
                ans.push_back(i);
            }
            else if (_count < _min) {
                ans.clear();
                ans.push_back(i);
                _min = _count;
            }
        }
        cin.ignore();

        for (i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
        ans.clear();
    }

    return 0;
}


