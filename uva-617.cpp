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

struct SIGNAL
{
    double L;
    int G;
    int Y;
    int R;
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j, k, l, h, test = 1, comma;
    double t, temp;
    SIGNAL sig;
    vector<SIGNAL>all;
    vector<int>ans;
    bool yes;

    while (cin >> n) {

        if (n == -1) {
            break;
        }

        all.clear();
        while (n--) {
            cin >> sig.L >> sig.G >> sig.Y >> sig.R;
            all.push_back(sig);
        }

        ans.clear();
        for (m = 30; m <= 60; m++) {
            yes = true;
            for (i = 0; i < all.size(); i++) {
                //t = all[i].L / m; /// t is in hour
                //t *= 3600; /// t is in seconds
                t = (all[i].L * 3600.0) / m;
                //cout << "t1 : " << t << "\n";
                k = all[i].G + all[i].Y + all[i].R;
                //cout << "k : " << k << "\n";
                //cout << fmod(t, k) << "\n";
                t = fmod(t, k);
                //t = fmod(t + 0.01, k);
                //cout << "t2 : " << t << "\n";
                //cout << fmod(906.0, 3.0) << "\n";

                //if (fmod(t, k) > all[i].G + all[i].Y && fmod(t, k) < all[i].G + all[i].Y + all[i].R) {
                if (t > all[i].G + all[i].Y && t < all[i].G + all[i].Y + all[i].R) {
                    yes = false; /// can not go at speed m

                    //cout << m << ": " << i + 1 << " ";
                    break;
                }
                //cout << "\n";
            }

            if (yes) {
                ans.push_back(m);
            }
        }

        /*
        for (i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        */

        cout << "Case " << test++ << ": ";
        if (!ans.size()) {
            cout << "No acceptable speeds.\n";
        }
        else {
            comma = 0;
            for (i = 0; i < ans.size(); i++) {

                l = h = ans[i];
                j = i + 1;
                k = ans[i] + 1;

                while (true) {
                    if (ans[j] == k) {
                        h = ans[j];
                        j++;
                        k++;
                    }
                    else {
                        break;
                    }
                }

                if (comma != 0) {
                        cout << ", ";
                }
                comma++;

                if (l == h) {
                    cout << l;
                }
                else {
                    cout << l << "-" << h;
                }

                i = j - 1;

            }
            cout << "\n";
        }
    }

    return 0;
}


