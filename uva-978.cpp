#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define NONE 0
#define GREEN 1
#define BLUE 2

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

struct PLAYER
{
    string team;
    int power;

    PLAYER()
    {

    }

    PLAYER(string t, int p)
    {
        team = t;
        power = p;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, b, sg, sb, p, i, j, k;
    multiset<int, greater<int> >green, blue;
    multiset<int, greater<int> >::iterator it;
    queue<PLAYER>winner;
    PLAYER who;
    int result;

    cin >> test;
    for (t = 1; t <= test; t++) {
        if (t != 1) {
            cout << "\n";
        }

        cin >> b >> sg >> sb;
        green.clear();
        blue.clear();
        while (sg--) {
            cin >> p;
            green.insert(p);
        }
        while (sb--) {
            cin >> p;
            blue.insert(p);
        }

        while (true) {

            for (i = 1; i <= b; i++) {
                it = green.begin();
                if (it != green.end()) {
                    sg = *it;
                    green.erase(it);
                }
                else {
                    sg = -1;
                }

                it = blue.begin();
                if (it != blue.end()) {
                    sb = *it;
                    blue.erase(it);
                }
                else {
                    sb = -1;
                }

                if (sg == sb) {
                    /// either both lists are empty
                    /// or both soldier have same power i.e. both are dead
                }
                else if (sg != -1 && sb == -1) {
                    winner.push(PLAYER(string("green"), sg));
                }
                else if (sg == -1 && sb != -1) {
                    winner.push(PLAYER(string("blue"), sb));
                }
                else {
                    p = abs(sg - sb);
                    if (sg > sb) {
                        winner.push(PLAYER(string("green"), p));
                    }
                    else {
                        winner.push(PLAYER(string("blue"), p));
                    }
                }
            }

            while (!winner.empty()) {
                who = winner.front();
                winner.pop();

                if (who.team == "green") {
                    green.insert(who.power);
                }
                else {
                    blue.insert(who.power);
                }
            }

            if (green.empty() && blue.empty()) {
                result = NONE;
                break;
            }
            else if (green.empty()) {
                result = BLUE;
                break;
            }
            else if (blue.empty()) {
                result = GREEN;
                break;
            }
        }

        if (result == NONE) {
            cout << "green and blue died";
        }
        else if (result == GREEN) {
            cout << "green wins";
            for (it = green.begin(); it != green.end(); it++) {
                cout << "\n" << *it;
            }
        }
        else {
            cout << "blue wins";
            for (it = blue.begin(); it != blue.end(); it++) {
                cout << "\n" << *it;
            }
        }

        cout << "\n";
    }

    return 0;
}


