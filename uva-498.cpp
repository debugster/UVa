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

vector<ll>allC;
vector<ll>allX;
ll P[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll c, x, i, j, n;
    string strC, strX;

    while (getline(cin, strC)) {
        getline(cin, strX);

        //cout << strC << "\n" << strX << "\n";


        extractNumberFromString(strC, allC);
        extractNumberFromString(strX, allX);

        /*
        for (i = 0; i < allC.size(); i++) {
            printf("%d ", allC[i]);
        }
        printf("\n");
        for (i = 0; i < allX.size(); i++) {
            printf("%d ", allX[i]);
        }
        printf("\n");
        */

        /// Applying Horner's Rule
        n = allC.size() - 1;
        reverse(allC.begin(), allC.end());
        P[n] = allC[n];
        for (j = 0; j < allX.size(); j++) {
            x = allX[j];
            for (i = n - 1; i >= 0; i--) {
                P[i] = P[i + 1] * x + allC[i];
            }
            printf("%lld", P[0]);
            if (j == allX.size() - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }

    return 0;
}
