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

    int n, a, b, c, x, y, z;
    bool found;

    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        found = false;
        for (x = -100; x <= 100 && !found; x++) {
            for (y = -100; y <= 100 && !found; y ++) {
                for (z = -100; z <= 100 && !found; z++) {
                    if (x != y && y != z && z != x && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                        cout << x << " " << y << " " << z << "\n";
                        found = true;
                    }
                }
            }
        }

        if (!found) {
            cout << "No solution.\n";
        }
    }

    return 0;
}


