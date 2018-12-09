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

/// check if x and y have unique digits
bool check(int x, int y)
{
    vector<int>freq(10, 0);
    int i, d, e;
    string a = to_string(x);
    string b = to_string(y);

    while (a.size() != 5) {
        a = '0' + a;
    }
    while (b.size() != 5) {
        b = '0' + b;
    }

    for (i = 0; i < 5; i++) {
        d = a[i] - '0';
        freq[d]++;

        e = b[i] - '0';
        freq[e]++;

        if (freq[d] > 1 || freq[e] > 1) {
            return false;
        }
    }

    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, test = 1, x, y;
    bool found;

    while (cin >> n) {
        if (!n) {
            break;
        }

        if (test != 1) {
            cout << "\n";
        }
        test++;

        /// x -> numerator, y -> denominator
        /// x / y = n; so x = n * y
        found = false;
        for (y = 1234; y <= 98765 / n; y++) {
            x = n * y;
            if (check(x, y)) {
                cout << setw(5) << setfill('0') << x << " / " << setw(5) << setfill('0') << y << " = " << n << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "There are no solutions for " << n << ".\n";
        }
    }

    return 0;
}


