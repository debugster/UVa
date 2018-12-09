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

    ll test, i, c, d, k, n, m, p1, p2, sum, mPower;
    vector<ll>coefficient;

    cin >> test;
    while (test--) {
        cin >> n;
        coefficient.clear();
        for (i = 0; i <= n; i++) {
            cin >> c;
            coefficient.push_back(c);
        }

        cin >> d >> k;

        /// find m
        p2 = 0;
        for (m = 1; ; m++) {
            p1 = p2;
            p2 += m * d;

            if (p1 < k && k <= p2) {
                break;
            }
        }

        sum = 0;
        mPower = 1;
        for (i = 0; i < coefficient.size(); i++) {
            sum += coefficient[i] * mPower;
            mPower *= m;
        }

        cout << sum << "\n";
    }

    return 0;
}


