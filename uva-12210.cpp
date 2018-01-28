#include <bits/stdc++.h>

using namespace std;

void fastScan(int &number);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int b, s, i, age, test = 1;
    //vector<int>bachelor, spinster;
    int bachelor[10005];

    while (scanf("%d%d", &b, &s)) {
        getchar();
        if (!b && !s) {
            break;
        }

        //bachelor.clear();
        //spinster.clear();

        for (i = 0; i < b; i++) {
            //scanf("%d", &age);
            //fastScan(age);
            //bachelor.push_back(age);
            fastScan(bachelor[i]);
        }
        for (i = 0; i < s; i++) {
            //scanf("%d", &age);
            fastScan(age);
            //spinster.push_back(age);
        }

        //sort(bachelor.begin(), bachelor.end());
        //sort(spinster.begin(), spinster.end());

        sort(bachelor, bachelor + b);

        printf("Case %d: ", test++);

        //if (bachelor.size() <= spinster.size()) {
        if (b <= s) {
            printf("0\n");
        }
        else {
            //printf("%d %d\n", bachelor.size() - spinster.size(), bachelor[0]);
            printf("%d %d\n", b - s, bachelor[0]);
        }
    }

    return 0;
}

void fastScan(int &number)
{
    /// Variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    /// Extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        /// Number is negative
        negative = true;

        /// Extract the next character from the buffer
        c = getchar();
    }

    /// Keep on extracting characters if they are integers
    /// i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number *10 + c - 48;

    /// If scanned input has a negative sign,
    /// Negate the value of the input number
    if (negative)
        number *= -1;
}
