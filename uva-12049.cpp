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

/* function ends */

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, m, v, f1, f2, total;
    unordered_map<int, int>List1, List2;
    unordered_map<int, int>::iterator it;

    cin >> test;
    while (test--) {
        cin >> n >> m;
        List1.clear();
        List2.clear();

        while (n--) {
            cin >> v;
            if (List1.find(v) == List1.end()) {
                List1[v] = 1;
            }
            else {
                List1[v]++;
            }
        }
        while (m--) {
            cin >> v;
            if (List2.find(v) == List2.end()) {
                List2[v] = 1;
            }
            else {
                List2[v]++;
            }
        }

        total = 0;
        for (it = List1.begin(); it != List1.end(); it++) {
            v = it->first;
            f1 = List1[v];
            f2 = List2[v];
            if (f1 > f2) {
                total += (f1 - f2);
            }
        }
        for (it = List2.begin(); it != List2.end(); it++) {
            v = it->first;
            f1 = List1[v];
            f2 = List2[v];
            if (f2 > f1) {
                total += (f2 - f1);
            }
        }
        cout << total << "\n";
    }

    return 0;
}


