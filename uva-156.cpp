#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int Len, i;
    char word[30], wordLower[30];
    set<string>temp, LIST;
    set<string>::iterator p;
    string s, sortedS, tempS;

    while (true) {
        scanf("%s", word);

        if (!strcmp(word, "#")) {
            break;
        }

        Len = strlen(word);
        for (i = 0; i < Len; i++) {
            wordLower[i] = tolower(word[i]);
        }
        wordLower[i] = '\0';

        s = word;
        sortedS = wordLower;
        sort(sortedS.begin(), sortedS.end());

        p = temp.find(sortedS);
        if (p == temp.end()) {
            temp.insert(sortedS);
            LIST.insert(s);
        }
        else {
            p = LIST.begin();
            while (p != LIST.end()) {
                tempS = *p;
                Len = tempS.size();
                for (i = 0; i < Len; i++) {
                    tempS[i] = tolower(tempS[i]);
                }
                sort(tempS.begin(), tempS.end());

                //cout << tempS << " - " << sortedS << "\n";

                if (tempS == sortedS) {
                    LIST.erase(p);
                    break;
                }
                p++;
            }
        }
    }

    p = LIST.begin();
    while (p != LIST.end()) {
        s = *p;
        printf("%s\n", s.c_str());
        //cout << *p << "\n";
        p++;
    }

    return 0;
}

