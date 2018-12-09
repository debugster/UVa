#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 1005

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

    int n, i, j, m, x, test = 1, d1, d2;
    int data[MAX];
    vector<int>allSum;
    vector<int>::iterator l, u;

    while (cin >> n) {
        if (!n) {
            break;
        }

        for (i = 0; i < n; i++) {
            cin >> data[i];
        }

        allSum.clear();
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                allSum.push_back(data[i] + data[j]);
            }
        }
        sort(allSum.begin(), allSum.end());

        /*
        for (i = 0; i < allSum.size(); i++) {
            cout << allSum[i] << " ";
        }
        cout << "\n";
        */

        cout << "Case " << test++ << ":\n";

        cin >> m;
        while (m--) {
            cin >> x;
            if (binary_search(allSum.begin(), allSum.end(), x)) {
                cout << "Closest sum to " << x << " is " << x << ".\n";
            }
            else {
                l = lower_bound(allSum.begin(), allSum.end(), x);
                u = upper_bound(allSum.begin(), allSum.end(), x);

                if ((l - allSum.begin()) == 0 && (u - allSum.begin()) == 0) {
                    cout << "Closest sum to " << x << " is " << *l << ".\n";
                }
                else if ((l - allSum.begin()) == allSum.size() && (u - allSum.begin()) == allSum.size()) {
                    cout << "Closest sum to " << x << " is " << *(l - 1) << ".\n";
                }
                else {
                    d1 = x - *(l - 1);
                    d2 = *u - x;

                    if (d1 < d2) {
                        cout << "Closest sum to " << x << " is " << *(l - 1) << ".\n";
                    }
                    else {
                        cout << "Closest sum to " << x << " is " << *u << ".\n";
                    }
                }
            }
        }
    }

    return 0;
}


