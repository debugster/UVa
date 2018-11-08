#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char text[][10] =   {   "Happy", "birthday", "to", "you",
                            "Happy", "birthday", "to", "you",
                            "Happy", "birthday", "to", "Rujia",
                            "Happy", "birthday", "to", "you"
                        };
    char person[MAX + 5][MAX + 5];
    int n, i, j, k, total;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", person[i]);
    }

    total = 0;
    do {
        total += 16;
    } while (total < n);

    for (i = 0, j = 0, k = 0; k < total; k++) {
        printf("%s: %s\n", person[i++], text[j++]);

        if (i == n) {
            i = 0;
        }
        if (j == 16) {
            j = 0;
        }
    }

    return 0;
}

