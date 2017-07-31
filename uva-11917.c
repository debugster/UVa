#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, n, i, d, done, *days;
    char **course, c[21];

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);

        days = (int *) malloc(n * sizeof(int));
        course = (char **) malloc(n * sizeof(char *));

        for (i = 0; i < n; i++) {
            course[i] = (char *) malloc(21 * sizeof(char));
        }

        for (i = 0; i < n; i++) {
            scanf("%s%d", course[i], &days[i]);
        }

        scanf("%d", &d);
        scanf("%s", c);

        printf("Case %d: ", t);

        done = 0;

        for (i = 0; i < n; i++) {
            if (!strcmp(course[i], c)) {
                if (days[i] <= d) {
                    printf("Yesss\n");
                }
                else if (days[i] <= d + 5) {
                    printf("Late\n");
                }
                else {
                    printf("Do your own homework!\n");
                }

                done = 1;
            }
            else if (i == n - 1 && done == 0) {
                printf("Do your own homework!\n");
            }
        }
    }
    return 0;
}
