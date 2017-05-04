#include <stdio.h>


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, k, remain, count, i;

    while (scanf("%d%d", &n, &k) != EOF) {
        count = remain = n;

        while (remain >= k) {
            i = remain / k;
            count += i;
            remain = i + (remain % k);
        }
        printf("%d\n", count);
    }
    return 0;
}

