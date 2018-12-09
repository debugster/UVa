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

    int test, tc, t, p, i, j;
    string str;
    set<int>temp[105];
    set<int>::iterator it;
    //string person[105];
    string person;
    set<string>all;
    stringstream ss;

    cin >> test;
    for (tc = 1; tc <= test; tc++) {

        cin >> p >> t;
        cin.ignore();
        for (i = 1; i <= p; i++) {
            temp[i].clear();
        }

        while (getline(cin, str)) {
            if (str == "") {
                break;
            }

            ss.clear();
            ss.str(str);
            ss >> i >> j;
            temp[i].insert(j);
        }

        all.clear();
        for (i = 1; i <= p; i++) {
            //person[i].clear();
            person.clear();
            for (it = temp[i].begin(); it != temp[i].end(); it++) {
                //person[i] += to_string(*it);
                person += to_string(*it);
            }
            //all.insert(person[i]);
            all.insert(person);
        }

        if (tc != 1) {
            cout << "\n";
        }

        cout << all.size() << "\n";
    }

    return 0;
}


