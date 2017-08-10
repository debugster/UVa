#include <bits/stdc++.h>

using namespace std;

vector<int>DIGIT(10000001, 0);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    double sum = 0, result;
    int i;

    for (i = 1; i <= 10000000; i++) {
        sum += log10(i);
        result = floor(sum) + 1;
        DIGIT[i] = result;
    }

    int test, n;
    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        printf("%d\n", DIGIT[n]);
    }

    return 0;
}
