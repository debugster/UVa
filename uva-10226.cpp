#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char word[100], c;
    int test, i, j, Len, total;
    string name;
    vector<string>trees;

    scanf("%d", &test);
    getchar();
    getchar();
    while (test--) {
        //printf("test - %d\n", test);
        while (true) {
            c = getchar();
            if (c == '\n' || c == EOF) {
                break;
            }
            else {
                ungetc(c, stdin);
            }
            gets(word);
            //puts(word);
            name = word;
            trees.push_back(name);
        }
        sort(trees.begin(), trees.end());
        Len = trees.size();

        /*
        for (i = 0; i < Len; i++) {
            cout << i << " " << trees[i] << endl;
        }
        */

        total = 1;
        for (i = 0; i < Len; i++) {
            name = trees[i];
            j = i + 1;
            while (j < Len && trees[j] == name) {
                total++;
                j++;
            }

            printf("%s %.4lf\n", name.c_str(), (100.0 * total) / Len);

            i = j - 1;
            total = 1;
        }

        if (test) {
            printf("\n");
        }

        trees.clear();
    }
    return 0;
}

