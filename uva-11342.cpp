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

struct TRIPLE
{
    int a;
    int b;
    int c;

    TRIPLE()
    {

    }

    void set(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }

    void order()
    {
        int sum = a + b + c;
        int _min = min(a, min(b, c));
        int _max = max(a, max(b, c));

        a = _min;
        c = _max;
        b = sum - _min - _max;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, k, s, a, b, c;
    int square[225], root[51000];
    bool found;
    map<int, TRIPLE>hashTable;
    vector<int>perfectSquare;
    TRIPLE t;

    for (k = 0; k <= 224; k++) {
        s = k * k;
        square[k] = s;
        root[s] = k;
        perfectSquare.push_back(s);
    }

    cin >> test;
    while (test--) {
        cin >> k;

        if (hashTable.find(k) != hashTable.end()) {
            cout << hashTable[k].a << " " << hashTable[k].b << " " << hashTable[k].c << "\n";
            continue;
        }

        found = false;
        for (a = 0; a <= 224 && !found; a++) {
            for (b = 0; b <= 224 && !found; b++) {


                c = k - square[a] - square[b];
                if (binary_search(perfectSquare.begin(), perfectSquare.end(), c)) {
                    t.set(a, b, root[c]);
                    t.order();
                    hashTable[k] = t;
                    cout << hashTable[k].a << " " << hashTable[k].b << " " << hashTable[k].c << "\n";
                    found = true;
                }

                /*
                for (c = 0; c <= 224 && !found; c++) {
                    if (square[a] + square[b] + square[c] == k) {
                        t.set(a, b, c);
                        t.order();
                        hashTable[k] = t;
                        cout << hashTable[k].a << " " << hashTable[k].b << " " << hashTable[k].c << "\n";
                        found = true;
                    }
                }
                */
            }
        }

        if (!found) {
            cout << "-1\n";
        }
    }

    return 0;
}


