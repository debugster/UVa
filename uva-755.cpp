#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)

/* macro ends */

/// A-0, B-1 ... Z-25
char charCode[] = "2223334445556667x77888999x"; /// x = Q, Z

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, i, j, k, len;
    char str[1005], ch;
    string numberStr;
    map<string, int>frequency;
    map<string, int>::iterator ptr;
    vector<pair<string, int> >multiple;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);
        frequency.clear();
        for (i = 1; i <= n; i++) {
            scanf("%s", str);
            //printf("%s\n");
            len = strlen(str);
            numberStr.clear();
            for (j = 0, k = 1; j < len && k <= 7; j++) {
                if (str[j] >= '0' && str[j] <= '9') {
                    numberStr += str[j];
                    k++;
                }
                else if (str[j] >= 'A' && str[j] <= 'Z') {
                    ch = charCode[str[j] - 'A'];
                    numberStr += ch;
                    k++;
                }
            }

            //printf("%s\n", numberStr.c_str());

            ptr = frequency.find(numberStr);
            if (ptr == frequency.end()) {
                frequency[numberStr] = 1;
                //frequency.insert(make_pair(numberStr, 1));
            }
            else {
                //k = ptr->second;
                //ptr->second = k + 1;
                ptr->second++;
            }
        }

        multiple.clear();
        ptr = frequency.begin();
        while (ptr != frequency.end()) {
            if (ptr->second >= 2) {
                multiple.push_back(make_pair(ptr->first, ptr->second));
            }
            ptr++;
        }

        if (t != 1) {
            printf("\n");
        }

        if (multiple.size() == 0) {
            printf("No duplicates.\n");
        }
        else {
            sort(multiple.begin(), multiple.end());
            for (i = 0; i < multiple.size(); i++) {
                numberStr = multiple[i].first;
                for (j = 0; j <= 2; j++) {
                    printf("%c", numberStr[j]);
                }
                printf("-");
                for (j = 3; j <= 6; j++) {
                    printf("%c", numberStr[j]);
                }

                printf(" %d\n", multiple[i].second);
            }
        }
    }

    return 0;
}
