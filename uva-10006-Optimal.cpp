#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        /// Only 15 Carmichael numbers between 2 and 65000
        switch (n) {
            case 561:
            case 1105:
            case 1729:
            case 2465:
            case 2821:
            case 6601:
            case 8911:
            case 10585:
            case 15841:
            case 29341:
            case 41041:
            case 46657:
            case 52633:
            case 62745:
            case 63973:
                printf("The number %d is a Carmichael number.\n", n);
                break;

            default:
                printf("%d is normal.\n", n);
                break;
        }
    }

    return 0;
}

