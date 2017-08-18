#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char input[100005], pos;
    int Len, i;
    string word;
    deque<string>realText;

    while (gets(input)) {
        Len = strlen(input);

        for (i = 0; i < Len; i++) {
            if (input[i] == '[' || input[i] == ']') {
                pos = input[i];
                break;
            }
            word.push_back(input[i]);
        }

        realText.push_back(word);
        word.clear();

        for (i++; i < Len; i++) {
            if (input[i] == '[' || input[i] == ']') {

                if (pos == '[') {
                    realText.push_front(word);
                }
                else {
                    realText.push_back(word);
                }

                word.clear();
                pos = input[i];
                continue;
            }

            word.push_back(input[i]);
        }

        if (pos == '[') {
            realText.push_front(word);
        }
        else {
            realText.push_back(word);
        }

        word.clear();

        deque<string>::iterator p = realText.begin();
        while (p != realText.end()) {
            cout << *p;
            ++p;
        }
        printf("\n");
        realText.clear();
    }
    return 0;
}
