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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1, c, s, i, m1, m2, a, b;
    double avg, ans;
    vector<int>mass;

    while (cin >> c >> s) {
        mass.clear();
        avg = 0.0;

        for (i = 1; i <= s; i++) {
            cin >> m1;
            mass.push_back(m1);
            avg += m1;
        }

        avg /= c;

        while (mass.size() != 2 * c) {
            mass.push_back(0);
        }

        sort(mass.begin(), mass.end());
        a = 0;
        b = mass.size() - 1;
        ans = 0;
        cout << "Set #" << test++ << "\n";

        for (i = 0; i < c; i++) {
            cout << " " << i << ":";

            m1 = mass[a];
            m2 = mass[b];

            if (m1 != 0) {
                cout << " " << m1;
            }
            if (m2 != 0) {
                cout << " " << m2;
            }
            cout << "\n";

            ans += abs((m1 + m2) - avg);

            a++;
            b--;
        }
        cout << "IMBALANCE = " << setprecision(5) << fixed << ans << "\n\n";
    }

    return 0;
}


