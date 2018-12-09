#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

/* function starts */

template<typename dataType>
dataType nthGrayCode(dataType n) /// n is 0-based
{
    return (n ^ (n >> 1));
}

/* function ends */

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, n, k;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &k);
        //n = k ^ (k >> 1);
        n = nthGrayCode(k);
        printf("%d\n", n);
    }

    return 0;
}
