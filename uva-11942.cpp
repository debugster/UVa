#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, data[10];
    bool order;

    printf("Lumberjacks:\n");

    scanf("%d", &test);
    while (test--) {
        for (i = 0; i < 10; i++) {
            scanf("%d", &data[i]);
        }

        if (data[0] < data[9]) {
            order = true;
            for (i = 0; i < 9; i++) {
                if (data[i] > data[i + 1]) {
                    order = false;
                    break;
                }
            }
        }
        else {
            order = true;
            for (i = 0; i < 9; i++) {
                if (data[i] < data[i + 1]) {
                    order = false;
                    break;
                }
            }
        }

        if (order) {
            printf("Ordered\n");
        }
        else {
            printf("Unordered\n");
        }
    }
    return 0;
}
