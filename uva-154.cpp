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

struct CITY
{
    string allocation;
    int serial;
    int score;

    CITY(string str, int ser, int sco)
    {
        allocation = str;
        serial = ser;
        score = sco;
    }

    bool operator<(const CITY &c)
    {
        if (score == c.score) {
            return serial < c.serial;
        }
        return score > c.score;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, n = 0;
    string str, temp;
    stringstream ss;
    map<string, int>freq; /// frequency table
    vector<CITY>all;

    while (cin >> str) {
        if (str == "#") {
            break;
        }
        else if (str[0] == 'e') {
            for (i = 0; i < all.size(); i++) {
                ss.clear();
                ss.str(all[i].allocation);

                while (ss >> str) {
                    all[i].score += freq[str];
                }
            }

            sort(all.begin(), all.end());
            cout << all[0].serial << "\n";

            n = 0;
            freq.clear();
            all.clear();
            continue;
        }
        else {
            for (i = 0; i < str.size(); i++) {
                if (str[i] == ',') {
                    str[i] = ' ';
                }
            }

            ss.clear();
            ss.str(str);
            while (ss >> temp) {
                if (freq.find(temp) == freq.end()) {
                    freq[temp] = 1;
                }
                else {
                    freq[temp]++;
                }
            }

            n++;
            all.push_back(CITY(str, n, 0));
            continue;
        }
    }

    return 0;
}


