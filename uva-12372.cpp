#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test, t, L, W, H;

    scanf("%d", &test);
    for(t = 1; t <= test; t++) {
        scanf("%d%d%d", &L, &W, &H);
        if(L <= 20 && W <= 20 && H <= 20) {
            printf("Case %d: good\n", t);
        }
        else {
            printf("Case %d: bad\n", t);
        }
    }

    return 0;
}
