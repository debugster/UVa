#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX_N 60
#define MAX_A 10005

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

vector<int>uniqueStamp[MAX_A]; /// keeps count who own the i-th stamp [for O(1) access]

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, i, j, m, a, totalUnique, who;
    double p;
    bool found;
    vector<int>all[MAX_N];
    int uniqueCount[MAX_N]; /// keeps count of unique stamps by i-th friend
    map<int, int>frequency;
    map<int, int>::iterator ptr;

    cin >> test;
    for (t = 1; t <= test; t++) {

        frequency.clear();
        for (i = 0; i < MAX_A; i++) {
            uniqueStamp[i].clear();
        }

        cin >> n;
        for (i = 0; i < n; i++) {
            all[i].clear();
            uniqueCount[i] = 0;
            cin >> m;
            while (m--) {
                cin >> a;

                /// check if he already have it
                found = false;
                for (j = 0; j < all[i].size(); j++) {
                    if (all[i][j] == a) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    continue;
                }

                all[i].push_back(a);
                if (frequency.find(a) == frequency.end()) {
                    frequency[a] = 1;
                }
                else {
                    frequency[a]++;
                }
                uniqueStamp[a].push_back(i);
            }
        }

        totalUnique = 0;
        for (ptr = frequency.begin(); ptr != frequency.end(); ptr++) {
            if (ptr->second == 1) {
                i = ptr->first;
                who = uniqueStamp[i][0];
                uniqueCount[who]++;
                totalUnique++;
            }
        }

        cout << "Case " << t << ":";
        for (i = 0; i < n; i++) {
            if (totalUnique == 0) {
                p = 0.0;
            }
            else {
                p = (uniqueCount[i] * 100.0) / totalUnique;
            }

            cout << " " << fixed << p << "%";
        }
        cout << "\n";
    }

    return 0;
}


