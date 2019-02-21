//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
    }
}

/* function ends */

struct TEAM
{
    int teamNo;
    int totalMember;
    vector<int>seatArrangement;

    TEAM()
    {

    }

    TEAM(int no, int member)
    {
        teamNo = no;
        totalMember = member;
    }

    bool operator<(const TEAM &op)
    {
        if (totalMember == op.totalMember) {
            return teamNo < op.teamNo;
        }
        return totalMember > op.totalMember;
    }


};

struct TABLE
{
    int tableNo;
    int capacity;

    TABLE()
    {

    }

    TABLE(int no, int cap)
    {
        tableNo = no;
        capacity = cap;
    }

    bool operator<(const TABLE &tb)
    {
        if (capacity == tb.capacity) {
            return tableNo < tb.tableNo;
        }
        return capacity > tb.capacity;
    }
};

bool compare(TEAM &t1, TEAM &t2)
{
    return t1.teamNo < t2.teamNo;
}

vector<TEAM>allTeam;
vector<TABLE>allTable;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int m, n, i, j, t, c, sum;
    bool possible;

    while (cin >> m >> n) {
        if (!m) {
            break;
        }

        allTeam.clear();
        allTable.clear();

        allTeam.push_back(TEAM(-1, 100000));
        allTable.push_back(TABLE(-1, 100000));

        for (i = 1; i <= m; i++) {
            cin >> c;
            allTeam.push_back(TEAM(i, c));
        }
        for (i = 1; i <= n; i++) {
            cin >> c;
            allTable.push_back(TABLE(i, c));
        }

        sort(allTeam.begin(), allTeam.end());
        sort(allTable.begin(), allTable.end());

        possible = true;
        for (i = 1; i <= m; i++) {
            sum = 0;
            for (j = 1, t = 1; j <= allTeam[i].totalMember && t <= n; t++) {
                if (allTable[t].capacity > 0) {
                    allTeam[i].seatArrangement.push_back(allTable[t].tableNo);
                    j++;
                    sum++;
                    allTable[t].capacity--;
                }
            }
            if (sum != allTeam[i].totalMember) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
            sort(allTeam.begin(), allTeam.end(), compare);
            for (i = 1; i <= m; i++) {
                for (j = 0; j < allTeam[i].seatArrangement.size() - 1; j++) {
                    cout << allTeam[i].seatArrangement[j] << " ";
                }
                cout << allTeam[i].seatArrangement[j] << "\n";
            }
        }
    }

    return 0;
}


