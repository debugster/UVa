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

bool checkNQueen(vector<int> &row)
{
    int i, j, r1, c1, r2, c2;

    /*
    for (i = 0; i < row.size(); i++) {
        cout << row[i] + 1 << " ";
    }
    cout << "\n";
    */

    for (i = 0; i < row.size() - 1; i++) {
        r1 = row[i];
        c1 = i;
        for (j = i + 1; j < row.size(); j++) {
            r2 = row[j];
            c2 = j;

            if (r1 == r2 || c1 == c2 || r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2) {
                //cout << "Q1 (" << r1 << ", " << c1 << ")\n";
                //cout << "Q2 (" << r2 << ", " << c2 << ")\n";
                return false;
            }
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

    int test, t, i, r, c, _count;
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int>row;

    cin >> test;
    for (t = 1; t <= test; t++) {
        cin >> r >> c;
        r--;
        c--;

        if (t != 1) {
            cout << "\n";
        }

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        row.clear();
        row.assign(num, num + 8);
        _count = 1;
        do {
            /*
            cout << " " << _count++ << "     ";
            for (i = 0; i < row.size(); i++) {
                cout << " " << row[i];
            }
            cout << "\n";
            */

            if (row[c] == r && checkNQueen(row)) {
                cout << setw(2) << _count++ << "     ";
                for (i = 0; i < row.size(); i++) {
                    cout << " " << row[i] + 1;
                }
                cout << "\n";
            }

        } while (next_permutation(row.begin(), row.end()));
    }

    return 0;
}


