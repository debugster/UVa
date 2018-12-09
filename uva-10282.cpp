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

    string s, s1, s2;
    stringstream ss;
    map<string, string>hashTable;

    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        ss.str(s);
        ss >> s1 >> s2;
        hashTable[s2] = s1;
        //cout << s1 << " " << s2 << "\n";
        ss.clear();
    }

    //cin.ignore();
    while (cin >> s2) {
        if (hashTable.find(s2) == hashTable.end()) {
            cout << "eh\n";
            continue;
        }
        cout << hashTable[s2] << "\n";
    }

    return 0;
}


