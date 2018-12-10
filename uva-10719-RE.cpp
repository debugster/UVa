#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int k, n, i, a, x, r;
    vector<int>allA, B;
    string str;
    stringstream ss;

    while (cin >> k) {
        //cin.ignore();
        getline(cin, str);

        allA.clear();
        ss.clear();
        ss.str(str);
        while (ss >> a) {
            allA.push_back(a);
        }

        reverse(allA.begin(), allA.end());

        B.clear();
        B.resize(allA.size());
        B[B.size() - 1] = 0;
        for (i = B.size() - 1; i >= 0; i--) {
            B[i - 1] = allA[i] + k * B[i];
        }

        reverse(B.begin(), B.end());
        cout << "q(x):";
        for (i = 1; i < B.size(); i++) {
            cout << " " << B[i];
        }
        r = (k * B[B.size() - 1]) + allA[0];
        cout << "\nr = " << r;
        cout << "\n\n";
    }

    return 0;
}

