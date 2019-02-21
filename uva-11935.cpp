#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define FUEL 0
#define LEAK 1
#define GAS 2
#define MECHANIC 3
#define GOAL 4
#define MAXIMUM_ITERATION 50

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

struct EVENT
{
    int d;
    int type;
    int n;
};

vector<EVENT>all;

bool canTravel(double capacity)
{
    int i;
    double currentFuel = capacity;
    double currentRate = all[0].n / 100.0; /// decrease rate per km
    int currentLeak = 0;

    for (i = 1; i < all.size(); i++) {
        currentFuel -= ((all[i].d - all[i - 1].d) * (currentRate + currentLeak));
        if (currentFuel < 0.0) {
            return false;
        }

        if (all[i].type == FUEL) {
            currentRate = all[i].n / 100.0;
        }
        else if (all[i].type == LEAK) {
            currentLeak++;
        }
        else if (all[i].type == GAS) {
            currentFuel = capacity;
        }
        else if (all[i].type == MECHANIC) {
            currentLeak = 0;
        }
        else {
            /// Goal
            break;
        }
    }

    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, n, i;
    string str;
    double low, mid, high, ans;

    while (cin >> d >> str) {
        if (str == "Fuel") {
            cin >> str >> n;
            if (!d && !n) {
                return 0;
            }

            all.push_back({d, FUEL, n});
        }
        else if (str == "Leak") {
            all.push_back({d, LEAK, -1});
        }
        else if (str == "Gas") {
            cin >> str; /// ignore "station"
            all.push_back({d, GAS, -1});
        }
        else if (str == "Mechanic") {
            all.push_back({d, MECHANIC, -1});
        }
        /// Goal
        else {
            all.push_back({d, GOAL, -1});

            low = 0.0;
            high = 10000.0;
            mid = 0.0;
            ans = 0.0;

            /// using Bi-Section technique to guess the answer
            for (i = 0; i < MAXIMUM_ITERATION; i++) {
                mid = (low + high) / 2.0;
                if (canTravel(mid)) {
                    ans = mid;
                    high = mid;
                }
                else {
                    low = mid;
                }
            }

            cout << setprecision(3) << fixed << ans << "\n";
            all.clear();
        }
    }

    return 0;
}


