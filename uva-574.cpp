#include <bits/stdc++.h>

using namespace std;

char TABLE[4096][13];
char binary[13];

void decToBin(int dec);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, j, t, n, sum, Limit, first, number[12];
    set<string>adderList;
    set<string>::iterator p;
    string str;
    bool found;

    /// Building Sub set Table
    binary[12] = '\0';
    for (i = 1; i < 4096; i++) {
        decToBin(i);
        strcpy(TABLE[i], binary);
    }

    while (scanf("%d%d", &t, &n)) {
        if (!t && !n) {
            break;
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &number[i]);
        }

        printf("Sums of %d:\n", t);

        adderList.clear();
        Limit = (1 << n) - 1;
        first = 12 - n;
        found = false;
        while (Limit > 0) {
            sum = 0;
            //adder.clear();
            str.clear();
            for (i = first, j = 0; i <= 11; i++, j++) {
                if (TABLE[Limit][i] == '1') {
                    sum += number[j];
                    //adder.push_back(number[j]);
                    str += to_string(number[j]);
                    str += "+";
                }
            }
            str.pop_back();
            if (sum == t) {
                p = adderList.find(str);
                if (p == adderList.end()) {
                    printf("%s\n", str.c_str());
                    adderList.insert(str);
                }
                found = true;
            }
            Limit--;
        }

        if (!found) {
            printf("NONE\n");
        }
    }

    return 0;
}

void decToBin(int dec)
{
    int index = 11, digit;

    /// binary[12] = '\0';

    do {
        digit = dec % 2;
        binary[index--] = digit + 48;
        dec /= 2;
    } while (dec > 0);

    while (index >= 0) {
        binary[index--] = '0';
    }
}
