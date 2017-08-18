#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, Letter, number;
    char Lic[10];

    scanf("%d", &test);
    while (test--) {
        scanf("%s", Lic);

        Letter = (Lic[0] - 'A') * 676 + (Lic[1] - 'A') * 26 + (Lic[2] - 'A');
        number = (Lic[4] - '0') * 1000 + (Lic[5] - '0') * 100 + (Lic[6] - '0') * 10 + (Lic[7] - '0');

        if (abs(Letter - number) <= 100) {
            printf("nice\n");
        }
        else {
            printf("not nice\n");
        }
    }
    return 0;
}
