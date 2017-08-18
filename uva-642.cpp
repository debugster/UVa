#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<string>dictOrig, dictCopy, wordList;
    string str, senti = "XXXXXX";
    char s[10];
    int i, j, Limit, Limit2;
    bool found;

    while (true) {
        scanf("%s", s);
        str = s;
        if (str == senti) {
            break;
        }
        dictOrig.push_back(str);
        dictCopy.push_back(str);
    }

    while (true) {
        scanf("%s", s);
        str = s;
        if (str == senti) {
            break;
        }
        wordList.push_back(str);
    }

    sort(dictOrig.begin(), dictOrig.end());
    sort(dictCopy.begin(), dictCopy.end());

    Limit = dictCopy.size();
    for (i = 0; i < Limit; i++) {
        sort(dictCopy[i].begin(), dictCopy[i].end());
    }

    Limit2 = wordList.size();
    for (i = 0; i < Limit2; i++) {
        sort(wordList[i].begin(), wordList[i].end());

        found = false;
        for (j = 0; j < Limit; j++) {
            if (wordList[i] == dictCopy[j]) {
                printf("%s\n", dictOrig[j].c_str());
                found = true;
            }
        }
        if (!found) {
            printf("NOT A VALID WORD\n");
        }
        printf("******\n");
    }

    return 0;
}

