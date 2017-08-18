#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int step, mod, seed_prev, seed_now;
    vector<int>seed;

    while (scanf("%d%d", &step, &mod) != EOF) {
        seed.clear();
        seed_prev = mod - step;
        seed_now = (seed_prev + step) % mod;
        seed.push_back(seed_now);
        seed_prev = seed_now;

        do {
            seed_now = (seed_prev + step) % mod;
            seed_prev = seed_now;
            seed.push_back(seed_now);
        } while (seed_now != seed[0]);

        printf("%10d%10d    ", step, mod);

        if (seed.size() - 1 == mod) {
            printf("Good Choice\n\n");
        }
        else {
            printf("Bad Choice\n\n");
        }
    }

    return 0;
}

