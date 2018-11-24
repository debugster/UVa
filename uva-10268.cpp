#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX 1000005

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
ll P[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll c, x, i, j, n;
    string strC;

    while (scanf("%lld", &x) != EOF) {
        getchar();
        getline(cin, strC);

        //cout << strC << "\n";

        extractNumberFromString(strC, allC);

        /*
        for (i = 0; i < allC.size(); i++) {
            printf("%d ", allC[i]);
        }
        printf("\n");
        */

        /// Applying Horner's Rule
        n = allC.size() - 1;
        reverse(allC.begin(), allC.end());

        if (!x) {
            if (n == 0) {
                printf("0\n");
            }
            else {
                printf("%lld\n", allC[1]);
            }
            continue;
        }

        P[n] = allC[n] * n;
        allC[0] = 0;
        for (i = n - 1, j = 1; i >= 0; i--, j++) {
            P[i] = (P[i + 1] * x) + (allC[i] * n) - (allC[i] * j);
        }
        printf("%lld\n", P[0] / x);
    }

    return 0;
}
