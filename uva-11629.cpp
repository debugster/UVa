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

    int p, g, i, a, b;
    char ch;
    string name, op;
    int perc, total;
    map<string, int>result;
    bool yes;

    cin >> p >> g;
    for (i = 1; i <= p; i++) {
        cin >> name >> a >> ch >> b; /// party_name x.y
        perc = a * 10 + b;
        result[name] = perc;
    }
    for (i = 1; i <= g; i++) {
        total = 0;
        while (cin >> name) {
            if (name == "+") {
                continue;
            }
            if (name == "=" || name == "<" || name == ">" || name == "<=" || name == ">=") {
                op = name;
                break;
            }

            total += result[name];
        }
        cin >> perc;
        perc *= 10;
        yes = false;
        if ((op == "=" && total == perc) || (op == "<" && total < perc) || (op == ">" && total > perc) || (op == "<=" && total <= perc) || (op == ">=" && total >= perc)) {
            yes = true;
        }

        cout << "Guess #" << i << " was ";
        //cout << "Guess #" << i << " was (" << total << " " << op << " " << perc << ") - ";
        if (yes) {
            cout << "correct.\n";
        }
        else {
            cout << "incorrect.\n";
        }
    }

    return 0;
}


