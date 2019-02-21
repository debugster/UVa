#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int k, n, i, a, x, r;
    vector<int>allP, allQ;
    string str;
    stringstream ss;

    while (cin >> k) {
        cin.ignore();
        getline(cin, str);

        allP.clear();
        ss.clear();
        ss.str(str);
        while (ss >> a) {
            allP.push_back(a);
        }

        reverse(allP.begin(), allP.end());
        n = allP.size() - 1; // degree of p(x)

        allQ.clear();
        allQ.assign(n + 1, 0);
        cout << "q(x):";
        for (i = n - 1; i >= 0; i--) {
            allQ[i] = allP[i + 1] + k * allQ[i + 1];
            cout << " " << allQ[i];
        }

        r = (k * allQ[0]) + allP[0];
        cout << "\nr = " << r;
        cout << "\n\n";
    }

    return 0;
}
