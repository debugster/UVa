#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char s[105], dump[105];
    string str;
    vector<string>LIST;
    int test, i, count, Len;

    scanf("%d", &test);
    while (test--) {
        scanf("%s", s);
        str = s;

        gets(dump);

        LIST.push_back(str);
    }

    sort(LIST.begin(), LIST.end());

    /*
    for (i = 0; i < LIST.size(); i++) {
        cout << LIST[i] << "\n";
    }
    */

    Len = LIST.size();
    str = LIST[0];
    i = 1;
    count = 1;

    while (i != Len) {
        if (str == LIST[i]) {
            count++;
        }
        else {
            printf("%s %d\n", str.c_str(), count);
            str = LIST[i];
            count = 1;
        }
        i++;
    }
    printf("%s %d\n", str.c_str(), count);

    return 0;
}

