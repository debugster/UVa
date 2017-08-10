#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int value;
    int freq;
} ASCII;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ASCII asc[127], temp;
    char text[1001];
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

        for (i = 32; i <= 125; i++) {
            for (j = i + 1; j <= 126; j++) {
                if (asc[i].freq > asc[j].freq) {
                    temp = asc[i];
                    asc[i] = asc[j];
                    asc[j] = temp;
                }
                else if (asc[i].freq == asc[j].freq) {
                    if (asc[i].value < asc[j].value) {
                        temp = asc[i];
                        asc[i] = asc[j];
                        asc[j] = temp;
                    }
                }
            }
        }

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
