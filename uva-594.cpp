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
#define MAX 32

/* macro ends */

int MAP[32] = {24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, i, j, r;
    bitset<MAX>rev;
    bool neg;

    while (scanf("%d", &x) != EOF) {
        bitset<MAX>b(x);

        rev.reset();
        for (i = 0; i <= 31; i++) {
            //rev.set(i, b[j]);
            rev[i] = b[MAP[i]];
        }

        neg = false;
        if (rev[31] == 1) {
            rev.flip();
            neg = true;
        }

        //cout << "b  : " << b << endl;
        //cout << "rev: " << rev << endl;

        r = 0;
        for (i = 30; i >= 0; i--) {
            r += (rev[i] * (1 << i));
        }

        if (neg) {
            r += 1;
            r *= -1;
        }

        printf("%d converts to %d\n", x, r);
    }

    return 0;
}
