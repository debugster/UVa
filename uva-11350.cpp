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

    int test, i;
    string str;
    long long currentA, currentB, leftA, leftB, rightA, rightB;

    cin >> test;
    while (test--) {
        cin >> str;

        leftA = 0;
        leftB = 1;
        currentA = currentB = 1;
        rightA = 1;
        rightB = 0;

        for (i = 0; i < str.size(); i++) {
            if (str[i] == 'L') {
                rightA = currentA;
                rightB = currentB;
            }
            else {
                leftA = currentA;
                leftB = currentB;
            }

            currentA = leftA + rightA;
            currentB = leftB + rightB;
        }

        cout << currentA << "/" << currentB << "\n";
    }

    return 0;
}


