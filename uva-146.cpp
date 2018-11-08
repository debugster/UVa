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



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char str[105];

    while (scanf("%s", str)) {
        if (!strcmp(str, "#")) {
            break;
        }

        if (next_permutation(str, str + strlen(str))) {
            printf("%s\n", str);
        }
        else {
            printf("No Successor\n");
        }
    }

    return 0;
}
