#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int f, n, i, j, k, finger, Len, maxLen;
    bool MAP[123], possible, previousPushed;
    char **word, dump;
    vector<int>possibleList;
    vector<string>finalList;
    string temp;

    while (scanf("%d%d", &f, &n) != EOF) {
        for (i = 0; i <= 122; i++) {
            MAP[i] = true;
        }

        for (i = 1; i <= f; i++) {
            scanf("%d", &finger);

            /// Marking all Letters related to broken fingers as false
            switch (finger) {
                case 1:
                    MAP['q'] = MAP['a'] = MAP['z'] = false;
                    break;
                case 2:
                    MAP['w'] = MAP['s'] = MAP['x'] = false;
                    break;
                case 3:
                    MAP['e'] = MAP['d'] = MAP['c'] = false;
                    break;
                case 4:
                    MAP['r'] = MAP['f'] = MAP['v'] = MAP['t'] = MAP['g'] = MAP['b'] = false;
                    break;
                case 5:
                case 6:
                    MAP[' '] = false;
                    break;
                case 7:
                    MAP['y'] = MAP['h'] = MAP['n'] = MAP['u'] = MAP['j'] = MAP['m'] = false;
                    break;
                case 8:
                    MAP['i'] = MAP['k'] = MAP[','] = false;
                    break;
                case 9:
                    MAP['o'] = MAP['l'] = MAP['.'] = false;
                    break;
                case 10:
                    MAP['p'] = MAP[';'] = MAP['/'] = false;
                    break;
            }
        }
        /// Discarding the Last new Line
        dump = getchar();

        word = (char **) malloc(n * sizeof(char *));
        for (i = 0; i < n; i++) {
            word[i] = (char *) malloc(52 * sizeof(char));
        }

        for (i = 0; i < n; i++) {
            scanf("%s", word[i]);
        }

        maxLen = -1;
        /// Maintaining a List consisting of those words' index number which are possible to type
        possibleList.clear();
        for (i = 0; i < n; i++) {
            Len = strlen(word[i]);

            possible = true;
            for (j = 0; j < Len; j++) {
                if (!MAP[word[i][j]]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                possibleList.push_back(i);
                if (Len > maxLen) {
                    maxLen = Len;
                }
            }
        }

        //printf("%d\n", maxLen);

        /// Maintaining a List to give the final output
        finalList.clear();
        /// j keeps count how many words are possible to type
        j = possibleList.size();
        for (i = 0; i < j; i++) {
            if (strlen(word[possibleList[i]]) == maxLen) {

                /// Checking if the word is pushed before into the finalList to avoid duplicity
                temp = word[possibleList[i]];
                previousPushed = false;
                for (k = finalList.size() - 1; k >= 0; k--) {
                    if (finalList[k] == temp) {
                        previousPushed = true;
                        break;
                    }
                }
                /// If the word was not pushed before, push it
                if (!previousPushed) {
                    finalList.push_back(temp);
                }
            }
        }

        sort(finalList.begin(), finalList.end());

        j = finalList.size();
        printf("%d\n", j);
        for (i = 0; i < j; i++) {
            printf("%s\n", finalList[i].c_str());
            //cout << finalList[i] << endl;
        }
    }
    return 0;
}
