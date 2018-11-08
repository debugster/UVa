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

struct PIXEL
{
    char ch;
    int _count;

    bool operator<(const PIXEL &p)
    {
        return _count > p._count;
    }
};

PIXEL frequency[26];

void initialize()
{
    for (int i = 0; i < 26; i++) {
        frequency[i].ch = i + 'A';
        frequency[i]._count = 0;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, r, c, i, j, m, n, _max, g1, g2, total;
    char ch;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d%d%d", &r, &c, &m, &n);
        getchar();

        initialize();
        for (i = 1; i <= r; i++) {
            for (j = 1; j <= c; j++) {
                ch = getchar();
                //printf("%c", ch);
                frequency[(int) ch - 'A']._count++;
            }
            getchar();
            //printf("\n");
        }

        sort(frequency, frequency + 26);
        /*
        for (i = 0; i < 26; i++) {
            printf("%c %d\n", frequency[i].ch, frequency[i]._count);
        }
        */
        _max = 1;
        i = 1;
        while (frequency[i]._count == frequency[0]._count) {
            _max++;
            i++;
        }

        g1 = _max * frequency[0]._count;
        g2 = (r * c) - g1;
        total = (g1 * m) + (g2 * n);
        printf("Case %d: %d\n", t, total);
    }

    return 0;
}
