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

struct PERSON
{
    string name;
    int dd;
    int mm;
    int yy;

    PERSON(string n, int d, int m, int y)
    {
        name = n;
        dd = d;
        mm = m;
        yy = y;
    }

    bool operator<(const PERSON &p)
    {
        if (yy == p.yy) {
            if (mm == p.mm) {
                return dd < p.dd;
            }
            return mm < p.mm;
        }
        return yy < p.yy;
    }
};

vector<PERSON>all;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, d, m, y;
    char s[20];
    string str;

    scanf("%d", &n);
    i = n;
    while (i--) {
        scanf("%s%d%d%d", s, &d, &m, &y);
        str = s;
        all.push_back(PERSON(str, d, m, y));
    }
    sort(all.begin(), all.end());
    printf("%s\n%s\n", all[n - 1].name.c_str(), all[0].name.c_str());

    return 0;
}
