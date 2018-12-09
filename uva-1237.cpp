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

struct CAR
{
    string name;
    int low;
    int high;

    CAR(string n, int l, int h)
    {
        name = n;
        low = l;
        high = h;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, d, i, l, h, q, p;
    string m;
    vector<CAR>all;
    vector<string>ans;

    cin >> test;
    for (t = 1; t <= test; t++) {
        all.clear();

        cin >> d;
        while (d--) {
            cin >> m >> l >> h;
            all.push_back(CAR(m, l, h));
        }

        if (t != 1) {
            cout << "\n";
        }

        cin >> q;
        while (q--) {
            cin >> p;
            ans.clear();
            for (i = 0; i < all.size(); i++) {
                if (p >= all[i].low && p <= all[i].high) {
                    ans.push_back(all[i].name);
                }

                if (ans.size() > 1) {
                    break;
                }
            }

            if (ans.size() == 1) {
                cout << ans[0] << "\n";
            }
            else {
                cout << "UNDETERMINED\n";
            }
        }
    }

    return 0;
}


