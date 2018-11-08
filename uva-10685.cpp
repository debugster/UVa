#include <bits/stdc++.h>

using namespace std;

#define child first
#define parent second

map<string, string>adj;
map<string, int>parentCount;
map<string, string>::iterator itr;
map<string, int>::iterator ptr;

string findRep(string x); /// find representative
void makeUnion(string u, string v);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string uS, vS;
    char uC[50], vC[50];
    int C, R, i, max;

    while (scanf("%d%d", &C, &R)) {
        if (!C && !R) {
            break;
        }

        adj.clear();
        parentCount.clear();

        for (i = 1; i <= C; i++) {
            scanf("%s", uC);
            uS = uC;
            adj.insert(pair<string, string>(uS, uS));
            parentCount.insert(pair<string, int>(uS, 0));
        }

        for (i = 1; i <= R; i++) {
            scanf("%s%s", uC, vC);
            uS = uC;
            vS = vC;
            makeUnion(uS, vS);
        }

        for (itr = adj.begin(); itr != adj.end(); itr++) {
            parentCount.find(itr->parent)->second++;
        }

        max = 0;
        for (ptr = parentCount.begin(); ptr != parentCount.end(); ptr++) {
            if (ptr->second > max) {
                max = ptr->second;
            }
        }
        printf("%d\n", max);
    }

    return 0;
}

string findRep(string x)
{
    if (adj.find(x)->parent == x) {
        return x;
    }

    adj.find(x)->parent = findRep(adj.find(x)->parent);
    return adj.find(x)->parent;
}

void makeUnion(string u, string v)
{
    string uR = findRep(u);
    string vR = findRep(v);

    if (uR != vR) {
        adj.find(uR)->parent = vR;
        for (itr = adj.begin(); itr != adj.end(); itr++) {
            if (itr->parent == uR) {
                itr->parent = vR;
            }
        }
    }
}
