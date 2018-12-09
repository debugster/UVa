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

struct compare
{
    bool operator()(int &a, int &b)
    {
        return a > b;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, v1, v2;
    ull sum, cost;
    priority_queue<int, vector<int>, compare>PQ;

    while (cin >> n) {

        if (!n) {
            break;
        }

        for (i = 0; i < n; i++) {
            cin >> v1;
            PQ.push(v1);
        }

        cost = 0;
        while (!PQ.empty()) {
            v1 = PQ.top();
            PQ.pop();

            if (PQ.empty()) {
                break;
            }
            v2 = PQ.top();
            PQ.pop();
            sum = v1 + v2;
            cost += sum;
            PQ.push(sum);
        }

        cout << cost << "\n";
    }

    return 0;
}

