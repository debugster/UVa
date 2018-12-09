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

struct RECIPE
{
    string name;
    ull cost;

    RECIPE()
    {
        /// empty
    }

    RECIPE(string n, int c)
    {
        name = n;
        cost = c;
    }

    bool operator<(const RECIPE &r)
    {
        if (cost == r.cost) {
            return name < r.name;
        }
        return cost < r.cost;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, m, n, k;
    ull b, c, x, sum;
    string binder, name, item;
    map<string, ull>itemPrice;
    vector<RECIPE>allRecipe;

    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; t++) {
        /*
        if (t != 1) {
            cout << "\n";
        }
        */

        getline(cin, binder);
        //cout << binder << "\n";
        cin >> m >> n >> b;
        cin.ignore();
        itemPrice.clear();
        allRecipe.clear();
        while (m--) {
            cin >> name >> c;
            cin.ignore();
            itemPrice[name] = c;
        }

        while (n--) {
            getline(cin, name);
            cin >> k;
            cin.ignore();
            sum = 0;
            while (k--) {
                cin >> item >> x;
                cin.ignore();
                sum += itemPrice[item] * x;
            }

            allRecipe.push_back(RECIPE(name, sum));
        }

        sort(allRecipe.begin(), allRecipe.end());
        for (c = 0; c < binder.size(); c++) {
            binder[c] = toupper(binder[c]);
        }
        cout << binder << "\n";
        sum = 0;
        for (c = 0; c < allRecipe.size(); c++) {
            if (allRecipe[c].cost <= b) {
                cout << allRecipe[c].name << "\n";
                sum++;
            }
        }
        if (!sum) {
            cout << "Too expensive!\n";
        }
        cout << "\n";
    }

    return 0;
}

