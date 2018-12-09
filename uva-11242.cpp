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

    int f, r, t, i, j;
    double s, maxS;
    vector<int>allF, allR;
    vector<double>dRatio;

    while (cin >> f) {
        if (!f) {
            break;
        }

        cin >> r;

        allF.clear();
        allR.clear();

        while (f--) {
            cin >> t;
            allF.push_back(t);
        }
        while (r--) {
            cin >> t;
            allR.push_back(t);
        }

        dRatio.clear();
        for (i = 0; i < allF.size(); i++) {
            for (j = 0; j < allR.size(); j++) {
                dRatio.push_back((allR[j] * 1.0) / allF[i]);
            }
        }
        sort(dRatio.begin(), dRatio.end());

        maxS = 0.0;
        for (i = 0; i < dRatio.size() - 1; i++) {
            s = dRatio[i + 1] / dRatio[i];
            maxS = max(maxS, s);
        }

        cout << setprecision(2) << fixed << maxS << "\n";
    }

    return 0;
}


