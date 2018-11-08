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

bool compare(string &a, string &b)
{
    string ab = a + b;
    string ba = b + a;

    if (ab > ba) {
        /// a should precede b
        return true;
    }

    /// b should precede a
    return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i;
    char s[1005];
    string str;
    vector<string>all;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        all.clear();
        for (i = 1; i <= n; i++) {
            scanf("%s", s);
            str = s;
            all.push_back(str);
        }
        sort(all.begin(), all.end(), compare);
        for (i = 0; i < n; i++) {
            printf("%s", all[i].c_str());
        }
        printf("\n");
    }

    return 0;
}
