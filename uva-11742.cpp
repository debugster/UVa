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

struct CONDITION
{
    int a;
    int b;
    int c;

    CONDITION()
    {

    }

    CONDITION(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j, k, a, b, c, pA, pB, dist, _count;
    int p[8];
    vector<CONDITION>allCon;
    CONDITION topC;
    bool valid;

    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }

        for (i = 0; i < n; i++) {
            p[i] = i;
        }

        allCon.clear();
        while (m--) {
            cin >> a >> b >> c;
            allCon.push_back(CONDITION(a, b, c));
        }

        _count = 0;
        /// generating all possible permutations
        do {
            valid = true;
            /// extracting all conditions
            for (i = 0; i < allCon.size(); i++) {
                a = allCon[i].a;
                b = allCon[i].b;
                c = allCon[i].c;

                /// looking for the current positions of a & b
                for (j = 0; j < n; j++) {
                    if (p[j] == a) {
                        pA = j;
                    }

                    if (p[j] == b) {
                        pB = j;
                    }
                }

                dist = abs(pA - pB);
                if ((c > 0 && dist > c) || (c < 0 && dist < abs(c))) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                _count++;
            }
        } while (next_permutation(p, p + n));

        cout << _count << "\n";
    }

    return 0;
}


