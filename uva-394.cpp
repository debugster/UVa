#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii; /// first -> lower, second -> upper

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define MAX_D 11

/* macro ends */

struct ARRAY
{
    string name;
    int baseAddress; /// B
    int elementSize; /// C_D
    int dimension; /// D
    pii bounds[MAX_D];
    int calculatedC[MAX_D]; /// Ci, 0 <= i <= D
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, i, j, b, c, d, l, u, no;
    int start = 0, address, index[MAX_D];
    char s[20];
    string name;
    ARRAY a;
    vector<ARRAY>all;
    map<string, int>hashTable;

    scanf("%d%d", &n, &r);
    all.clear();
    hashTable.clear();
    for (i = 1; i <= n; i++) {
        scanf("%s%d%d%d", s, &b, &c, &d);

        a.name = s;
        a.baseAddress = b;
        a.elementSize = c;
        a.dimension = d;

        hashTable[a.name] = start++;

        for (j = 1; j <= d; j++) {
            scanf("%d%d", &l, &u);
            a.bounds[j].first = l;
            a.bounds[j].second = u;
        }

        a.calculatedC[d] = c;
        for (j = d - 1; j >= 1; j--) {
            a.calculatedC[j] = a.calculatedC[j + 1] * (a.bounds[j + 1].second - a.bounds[j + 1].first + 1);
        }
        a.calculatedC[0] = a.baseAddress;
        for (j = 1; j <= d; j++) {
            a.calculatedC[0] -= a.calculatedC[j] * a.bounds[j].first;
        }

        all.push_back(a);
    }

    for (i = 1; i <= r; i++) {
        scanf("%s", s);
        name = s;
        no = hashTable[name];

        address = all[no].calculatedC[0];

        for (j = 1; j <= all[no].dimension; j++) {
            scanf("%d", &index[j]);
            address += all[no].calculatedC[j] * index[j];
        }

        printf("%s[", all[no].name.c_str());
        for (j = 1; j < all[no].dimension; j++) {
            printf("%d, ", index[j]);
        }
        printf("%d] = %d\n", index[j], address);
    }

    return 0;
}
