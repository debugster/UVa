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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, maxLen, rows, cols, r, index;
    char s[100];
    string str;
    vector<string>names;

    while (scanf("%d", &n) != EOF) {
        //getchar();
        names.clear();
        maxLen = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", s);
            str = s;
            names.push_back(str);
            maxLen = max(maxLen, (int) str.size());
        }

        sort(names.begin(), names.end());

        for (i = 1; i <= 60; i++) {
            printf("-");
        }
        printf("\n");

        ///cols = 60 - maxLen;
        ///cols = cols / (maxLen + 2);
        ///cols++;
        cols = ((60 - maxLen) / (maxLen + 2)) + 1;

        /*
        i = 2;
        while (true) {
            if (cols * i >= n) {
                break;
            }
            i++;
        }
        rows = i;
        cols = ceil(n / (rows * 1.0));
        */

        rows = ceil(n / (cols * 1.0));

        for (r = 1; r <= rows; r++) {
            for (i = 0; i < cols; i++) {
                index = i * rows + r;

                if (index > names.size()) {
                    continue;
                }

                /*
                if (i == cols - 1) {
                    printf("%-*s", maxLen, names[index - 1].c_str());
                }
                else {
                    printf("%-*s", maxLen + 2, names[index - 1].c_str());
                }
                */


                if (i == 0) {
                    printf("%-*s", maxLen, names[index - 1].c_str());
                }
                else {
                    printf("  %-*s", maxLen, names[index - 1].c_str());
                }

            }
            printf("\n");
        }
    }

    return 0;
}
