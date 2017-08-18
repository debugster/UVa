#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    set<string>conLIST;
    vector<string>ListA, ListB;
    string temp;
    int test, t, m, n, i, j, s;
    char word[30], c;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d%d", &m, &n);
        c = getchar();

        ListA.clear();
        for (i = 1; i <= m; i++) {
            gets(word);
            temp = word;
            ListA.push_back(temp);
        }

        ListB.clear();
        for (i = 1; i <= n; i++) {
            gets(word);
            temp = word;
            ListB.push_back(temp);
        }

        conLIST.clear();
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                temp = ListA[i] + ListB[j];
                conLIST.insert(temp);
            }
        }

        printf("Case %d: %d\n", t, conLIST.size());
    }

    return 0;
}
