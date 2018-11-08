#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int initPos, currentPos, a, b, c, d, total;

    while (scanf("%d%d%d%d", &initPos, &a, &b, &c), (initPos || a || b || c)) {
        /// clockwise 2 full turns
        total = 80;
        currentPos = initPos;

        /// stop at 1st number of combination in clockwise turn
        if (currentPos >= a) {
            d = currentPos - a;
        }
        else {
            d = 40 - (a - currentPos);
        }
        total += d;
        currentPos = a;

        /// counter-clockwise 1 full turn
        total += 40;

        /// continue turning counter-clockwise until the 2nd number is reached
        if (currentPos <= b) {
            d = b - currentPos;
        }
        else {
            d = (40 - currentPos) + b;
        }
        total += d;
        currentPos = b;

        /// turn the dial clockwise again until the 3rd number is reached
        if (currentPos >= c) {
            d = currentPos - c;
        }
        else {
            d = 40 - (c - currentPos);
        }
        total += d;
        currentPos = c;

        total *= 9;
        printf("%d\n", total);
    }

    return 0;
}

