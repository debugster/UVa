#include <bits/stdc++.h>
#define MAX 9999
using namespace std;

bool takenList[MAX + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int k, m, i, j, courseCode, totalCourse, minCourse, count, fulfilCount;

    while (scanf("%d", &k), k) {
        scanf("%d", &m);

        memset(takenList, 0, sizeof(takenList));
        for (i = 1; i <= k; i++) {
            scanf("%d", &courseCode);
            takenList[courseCode] = true;
        }

        fulfilCount = 0; /// counts how many category he have fulfilled
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &totalCourse, &minCourse);
            count = 0; /// counts total number of courses taken from a specific category
            for (j = 1; j <= totalCourse; j++) {
                scanf("%d", &courseCode);
                if (takenList[courseCode]) {
                    count++;
                }
            }
            if (count >= minCourse) {
                fulfilCount++;
            }
        }

        if (fulfilCount == m) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return 0;
}

