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

struct Q
{
    int id;
    int period;
    int repeat;

    Q()
    {
        /// empty
    }

    Q(int i, int p)
    {
        id = i;
        period = repeat = p;
    }
};

struct compare
{
    bool operator()(Q &a, Q &b)
    {
        if (a.repeat == b.repeat) {
            return a.id > b.id;
        }
        return a.repeat > b.repeat;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int i, p, k;
    Q q;
    priority_queue<Q, vector<Q>, compare>PQ;

    while (cin >> str) {
        if (str == "#") {
            break;
        }
        cin >> i >> p;
        PQ.push(Q(i, p));
    }
    cin >> k;
    while (k--) {
        q = PQ.top();
        PQ.pop();
        cout << q.id << "\n";
        q.repeat += q.period;
        PQ.push(q);
    }

    return 0;
}


