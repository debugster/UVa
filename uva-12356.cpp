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
#define MAX 100005

/* macro ends */

struct node
{
    //int n;
    int left;
    int right;
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, b, i, l, r, ansL, ansR, tempL, tempR;
    bool noneL, noneR;
    node soldier[MAX];

    while (scanf("%d%d", &s, &b), s != 0, b != 0) {
        //soldier[0].n = soldier[s + 1].n = -1;
        soldier[1].left = soldier[s].right = -1;

        for (i = 1; i <= s; i++) {
            if (s == 1) {
                break;
            }

            if (i == 1) {
                soldier[i].right = i + 1;
                continue;
            }
            else if (i == s) {
                soldier[i].left = i - 1;
                continue;
            }

            soldier[i].right = i + 1;
            soldier[i].left = i - 1;
        }

        for (i = 1; i <= b; i++) {
            scanf("%d%d", &l, &r);

            noneL = noneR = false;

            if (soldier[l].left == -1 && soldier[r].right == -1) {
                noneL = noneR = true;
            }
            else if (soldier[l].left == -1) {
                tempR = soldier[r].right;
                soldier[tempR].left = -1;
                noneL = true;
                ansR = tempR;
            }
            else if (soldier[r].right == -1) {
                tempL = soldier[l].left;
                soldier[tempL].right = -1;
                ansL = tempL;
                noneR = true;
            }
            else if (soldier[l].left != -1 && soldier[r].right != -1) {
                tempL = soldier[l].left;
                tempR = soldier[r].right;

                soldier[tempL].right = tempR;
                soldier[tempR].left = tempL;

                ansL = tempL;
                ansR = tempR;
            }

            if (noneL) {
                printf("* ");
            }
            else {
                printf("%d ", ansL);
            }

            if (noneR) {
                printf("*\n");
            }
            else {
                printf("%d\n", ansR);
            }
        }

        printf("-\n");
    }

    return 0;
}
