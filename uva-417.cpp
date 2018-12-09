#include <bits/stdc++.h>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

/* function starts */

template<typename dataType>
dataType nthGrayCode(dataType n) /// n is 0-based
{
    return (n ^ (n >> 1));
}

/* function ends */

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _count, Len;
    char a, b, c, d, e, s[10];
    string str[6];
    map<string, int>hashTable;

    _count = 1;
    for (Len = 1; Len <= 5; Len++) {
        for (a = 'a'; a <= 'z'; a++) {
            str[1] = a;

            if (Len == 1) {
                hashTable[str[1]] = _count++;
                //printf("%s - %d\n", str[1].c_str(), _count - 1);
                continue;
            }

            for (b = a + 1; b <= 'z'; b++) {
                str[2] = str[1] + b;

                if (Len == 2) {
                    hashTable[str[2]] = _count++;
                    //printf("%s - %d\n", str[2].c_str(), _count - 1);
                    continue;
                }

                for (c = b + 1; c <= 'z'; c++) {
                    str[3] = str[2] + c;

                    if (Len == 3) {
                        hashTable[str[3]] = _count++;
                        //printf("%s - %d\n", str[3].c_str(), _count - 1);
                        continue;
                    }

                    for (d = c + 1; d <= 'z'; d++) {
                        str[4] = str[3] + d;

                        if (Len == 4) {
                            hashTable[str[4]] = _count++;
                            //printf("%s - %d\n", str[4].c_str(), _count - 1);
                            continue;
                        }

                        for (e = d + 1; e <= 'z'; e++) {
                            str[5] = str[4] + e;

                            hashTable[str[5]] = _count++;
                            //printf("%s - %d\n", str[5].c_str(), _count - 1);
                        }
                    }
                }
            }
        }
    }

    while (gets(s)) {
        str[0] = s;
        if (hashTable.find(str[0]) == hashTable.end()) {
            printf("0\n");
        }
        else {
            printf("%d\n", hashTable[str[0]]);
        }
    }

    return 0;
}

