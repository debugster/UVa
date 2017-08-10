#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, wall, w, highJump, shortJump, *height;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &wall);

        height = (int *) malloc(wall * sizeof(int));
        highJump = shortJump = 0;
        for (w = 0; w < wall; w++) {
            scanf("%d", &height[w]);

            if (w > 0) {
                if (height[w - 1] > height[w]) {
                    shortJump++;
                }
                else if (height[w - 1] < height[w]) {
                    highJump++;
                }
            }
        }
        printf("Case %d: %d %d\n", t, highJump, shortJump);
    }
    return 0;
}
