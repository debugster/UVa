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

struct PERSON
{
    string title;
    string firstName;
    string lastName;
    string address;
    string dept;
    string homePhone;
    string workPhone;
    string cBox;

    bool operator<(const PERSON &p)
    {
        return lastName < p.lastName;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, i, j, limit;
    char dStr[1000], pStr[1000];
    int commaIndex[7];
    string temp;
    PERSON p;
    vector<PERSON>all;

    scanf("%d", &test);
    getchar();
    while (test--) {
        gets(dStr);
        //puts(d);

        while (gets(pStr)) {
            if (pStr[0] == '\0') {
                break;
            }
            //puts(p);

            limit = strlen(pStr);
            for (i = 0, j = 0; i < limit; i++) {
                if (pStr[i] == ',') {
                    commaIndex[j++] = i;
                }
            }
            commaIndex[j] = limit; /// null character

            temp = pStr;
            p.title = string(temp, 0, commaIndex[0]);
            p.firstName = string(temp, commaIndex[0] + 1, commaIndex[1] - commaIndex[0] - 1);
            p.lastName = string(temp, commaIndex[1] + 1, commaIndex[2] - commaIndex[1] - 1);
            p.address = string(temp, commaIndex[2] + 1, commaIndex[3] - commaIndex[2] - 1);
            p.dept = dStr;
            p.homePhone = string(temp, commaIndex[3] + 1, commaIndex[4] - commaIndex[3] - 1);
            p.workPhone = string(temp, commaIndex[4] + 1, commaIndex[5] - commaIndex[4] - 1);
            p.cBox = string(temp, commaIndex[5] + 1, commaIndex[6] - commaIndex[5] - 1);

            all.push_back(p);
        }
    }

    sort(all.begin(), all.end());
    for (i = 0; i < all.size(); i++) {
        printf("----------------------------------------\n");
        printf("%s %s %s\n", all[i].title.c_str(), all[i].firstName.c_str(), all[i].lastName.c_str());
        printf("%s\n", all[i].address.c_str());
        printf("Department: %s\n", all[i].dept.c_str());
        printf("Home Phone: %s\n", all[i].homePhone.c_str());
        printf("Work Phone: %s\n", all[i].workPhone.c_str());
        printf("Campus Box: %s\n", all[i].cBox.c_str());
    }

    return 0;
}
