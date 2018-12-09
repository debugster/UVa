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

    int n, cmd, v, sTop, qTop, pqTop;
    stack<int>S;
    queue<int>Q;
    priority_queue<int>PQ;
    bool isS, isQ, isPQ;

    while (cin >> n) {

        while (!S.empty()) {
            S.pop();
        }
        while (!Q.empty()) {
            Q.pop();
        }
        while (!PQ.empty()) {
            PQ.pop();
        }

        isS = isQ = isPQ = true;
        while (n--) {
            cin >> cmd >> v;
            if (cmd == 1) {
                S.push(v);
                Q.push(v);
                PQ.push(v);
            }
            else {
                if (S.empty()) {
                    isS = false;
                }
                else if (v == S.top()) {
                    S.pop();
                }
                else {
                    isS = false;
                }

                if (Q.empty()) {
                    isQ = false;
                }
                else if (v == Q.front()) {
                    Q.pop();
                }
                else {
                    isQ = false;
                }

                if (PQ.empty()) {
                    isPQ = false;
                }
                else if (v == PQ.top()) {
                    PQ.pop();
                }
                else {
                    isPQ = false;
                }
            }
        }

        if (!isS && !isQ && !isPQ) {
            cout << "impossible\n";
        }
        else if ((isS && isQ) || (isQ && isPQ) || (isPQ && isS)) {
            cout << "not sure\n";
        }
        else if (isS) {
            cout << "stack\n";
        }
        else if (isQ) {
            cout << "queue\n";
        }
        else {
            cout << "priority queue\n";
        }
    }

    return 0;
}


