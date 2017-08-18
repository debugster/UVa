#include <bits/stdc++.h>

using namespace std;

struct data
{
    int index;
    char value[30];
};

bool Less(data x, data y)
{
    return x.index < y.index;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, i, num, n;
    data x;
    char dump, str[30];
    vector<data>dataSet;

    scanf("%d", &test);
    while (test--) {
        n = 0;
        dataSet.clear();

        while (true) {
            scanf("%d", &num);
            n++;
            x.index = num;
            dataSet.push_back(x);
            while ((dump = getchar()) == ' ');
            ungetc(dump, stdin);
            if (dump == 10 || dump == -1) {
                break;
            }
        }

        for (i = 0; i < n; i++) {
            scanf("%s", str);
            strcpy(dataSet[i].value, str);
        }

        sort(dataSet.begin(), dataSet.end(), Less);

        for (i = 0; i < n; i++) {
            printf("%s\n", dataSet[i].value);
        }

        if (test != 0) {
            printf("\n");
        }
    }

    return 0;
}

