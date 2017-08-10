#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char input[100], dump;
    int test, Len, i, score, streak;

    scanf("%d", &test);
    dump = getchar();
    while (test--) {
        gets(input);
        Len = strlen(input);

        score = streak = 0;
        for (i = 0; i < Len; i++) {
            if (input[i] == 'O') {
                streak++;
                score += streak;
            }
            else {
                streak = 0;
            }
        }

        printf("%d\n", score);
    }

    return 0;
}
