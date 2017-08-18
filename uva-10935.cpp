#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    deque<int>deck;
    int n, i;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        deck.clear();

        for (i = 1; i <= n; i++) {
            deck.push_back(i);
        }

        printf("Discarded cards:");
        while (deck.size() > 1) {
            printf(" %d", deck.front());

            deck.pop_front();
            deck.push_back(deck.front());
            deck.pop_front();

            if (deck.size() != 1) {
                printf(",");
            }
            else {
                break;
            }
        }

        printf("\nRemaining card: %d\n", deck.front());
    }
    return 0;
}
