/*UVA-10055*/

#include <stdio.h>

int main()
{
    unsigned long long i,j,d;
    while(scanf("%llu%llu", &i, &j) != EOF) {
        if(i <= j) {
            d = j - i;
        }
        else {
            d = i - j;
        }
        printf("%llu\n", d);
    }
    return 0;
}
