#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

vector<int>Land;
const int LIMIT = 2500000;

bool compare(int &a, int &b)
{
    return a > b;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, p, i, total;
    bool found;

    scanf("%d", &test);
    while (test--) {
        Land.clear();
        while (scanf("%d", &p)) {
            if (!p) {
                break;
            }

            Land.push_back(p);
        }

        sort(Land.begin(), Land.end(), compare);
        total = 0;
        found = true;
        for (i = 0; i < Land.size(); i++) {
            total += (int) (pow(Land[i], i + 1) + 0.5);
            if (total > LIMIT) {
                found = false;
                break;
            }
        }

        if (found) {
            printf("%d\n", total * 2);
        }
        else {
            printf("Too expensive\n");
        }
    }

    return 0;
}
