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

    int i;
    char ch;
    string line, word, w;
    stringstream ss1, ss2;
    set<string>dict;
    set<string>::iterator it;

    while (getline(cin, line)) {

        if (line == "") {
            continue;
        }

        //cout << line << "\n";
        ss1.clear();
        ss1.str(line);
        while (ss1 >> word) {
            //cout << word << "\n";
            for (i = 0; i < word.size(); i++) {
                ch = word[i];
                if (ch >= 'A' && ch <= 'Z') {
                    ch = tolower(ch);
                    w += ch;
                }
                else if (ch >= 'a' && ch <= 'z') {
                    w += ch;
                }
                else {
                    dict.insert(w);
                    w = "";
                }
            }
            dict.insert(w);
            w = "";
        }
    }

    for (it = dict.begin(); it != dict.end(); it++) {

        if (*it == "") {
            continue;
        }

        cout << *it << "\n";
    }

    return 0;
}


