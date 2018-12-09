#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 10005

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

struct ELEMENT
{
    int row;
    int column;
    int value;

    ELEMENT()
    {
        /// empty
    }

    ELEMENT(int r, int c, int v)
    {
        row = r;
        column = c;
        value = v;
    }

    bool operator<(const ELEMENT &e)
    {
        if (row == e.row) {
            return column < e.column;
        }
        return row < e.row;
    }
};

void printMatrix(vector<int> &pos, vector<int> &values)
{
    cout << pos.size();
    for (int j = 0; j < pos.size(); j++) {
        cout << " " << pos[j];
    }
    cout << "\n";
    for (int j = 0; j < values.size(); j++) {
        cout << values[j];
        if (j != values.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    pos.clear();
    values.clear();
}

vector<int>pos;
vector<int>values;
vector<ELEMENT>transMatrix;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, i, j, k, l, p, q;
    ELEMENT e;
    int test = 1;

    while (cin >> m >> n) {
        transMatrix.clear();
        //cout << "Test = " << test++ << "\n";
        for (i = 1; i <= m; i++) {
            cin >> k;
            pos.clear();
            for (l = 0; l < k; l++) {
                cin >> p;
                pos.push_back(p);
            }
            for (l = 0; l < k; l++) {
                cin >> q;
                p = pos[l];
                transMatrix.push_back(ELEMENT(p, i, q));
            }
        }

        sort(transMatrix.begin(), transMatrix.end());

        /*
        for (k = 0; k < transMatrix.size(); k++) {
            e = transMatrix[k];
            cout << "matrix[" << e.row << "][" << e.column << "] = " << e.value << "\n";
        }
        */


        cout << n << " " << m << "\n";
        pos.clear();
        values.clear();
        for (k = 0, i = 1; i <= n;) {
            if (k < transMatrix.size()) {
                e = transMatrix[k];
            }
            else {
                e.row = -1;
                e.column = -1;
                e.value = -1;
            }

            if (e.row == i) {
                pos.push_back(e.column);
                values.push_back(e.value);
                k++;
            }
            else {
                printMatrix(pos, values);

                i++;
            }

            //cout << "i = " << i << " k = " << k << "\n";
        }
    }

    return 0;
}


