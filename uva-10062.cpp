#include <bits/stdc++.h>

using namespace std;

struct ASCII
{
    int value;
    int freq;

    bool operator<(const ASCII &op)
    {
        if (freq == op.freq) {
            return value > op.value;
        }
        return freq < op.freq;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ASCII asc[127];
    char text[10001];
    int Len, i, j, test = 1;

    while (gets(text)) {
        Len = strlen(text);

        for (i = 32; i <= 126; i++) {
            asc[i].value = i;
            asc[i].freq = 0;
        }

        for (i = 0; i < Len; i++) {
            asc[(int) text[i]].freq++;
        }

        sort(asc + 32, asc + 127);

        if (test != 1) {
            printf("\n");
        }
        test++;

        for (i = 32; i <= 126; i++) {
            if (asc[i].freq != 0) {
                printf("%d %d\n", asc[i].value, asc[i].freq);
            }
        }
    }

    return 0;
}
