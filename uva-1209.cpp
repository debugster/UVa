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

char user[100], temp[100];
int len;

int dist()
{
    int i, d = 100;

    for (i = 0; i < len - 1; i++) {
        d = min(d, (int) abs(user[i] - user[i + 1]));
    }

    return d;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int i, d, _d;
    char pass[100];

    while (gets(user)) {
        len = strlen(user);
        strcpy(temp, user);
        d = 0;

        i = 1;
        while (prev_permutation(user, user + len) && i <= 10) {
            //puts(user);
            _d = dist();
            if (d <= _d) {
                d = _d;
                strcpy(pass, user);
            }
            i++;
        }
        strcpy(user, temp);
        //printf("## %s ##\n", user);

        i = 0;
        do {
            //puts(user);
            _d = dist();
            if (d < _d) {
                d = _d;
                strcpy(pass, user);
            }
            i++;
        } while (next_permutation(user, user + len) && i <= 10);

        printf("%s%d\n", pass, d);
    }

    return 0;
}
