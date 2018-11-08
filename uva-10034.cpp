#include <bits/stdc++.h>

using namespace std;

/* something starts */
/* something ends */

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, int> pdi; /// double -> key(weight), int -> node

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define INF 0X7FFFFFFF
#define MAX_NODE 105

/* macro ends */

double matrix[MAX_NODE][MAX_NODE];

struct point
{
    double x;
    double y;
    double d; /// distance from the reference point
};

struct compare
{
    bool operator()(pdi &a, pdi &b)
    {
        return a.first > b.first;
    }
};

double MSTPrim(int source, int nodes);
void printMatrix(int nodes);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, t, n, i, j, _count;
    double min_x, min_y, dx, dy, ans;
    point p;
    vector<point> points;

    scanf("%d", &test);
    for (t = 1; t <= test; t++) {
        scanf("%d", &n);
        points.clear();

        min_x = min_y = INF;
        p.d = 0.0;
        for (i = 1; i <= n; i++) {
            scanf("%lf%lf", &p.x, &p.y);
            points.push_back(p);
            //min_x = min(min_x, p.x);
            //min_y = min(min_y, p.y);
        }

        //bool alreadyCalculated[MAX_NODE][MAX_NODE];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) {
                    matrix[i][j] = INF;
                    continue;
                }

                dx = abs(points[i].x - points[j].x);
                dy = abs(points[i].y - points[j].y);

                dx *= dx;
                dy *= dy;

                matrix[i][j] = sqrt(dx + dy);
            }
        }

        //printMatrix(n);
        if (t != 1) {
            printf("\n");
        }
        printf("%.2lf\n", MSTPrim(0, n));
    }

    return 0;
}

double MSTPrim(int source, int nodes)
{
    priority_queue<pdi, vector<pdi>, compare> PQ;
    vector<bool> inMST(nodes, false);
    vector<double> key(nodes, INF);
    vector<int> parent(nodes, -1);
    int _count = 0, u, v, last;
    pdi p;
    double ans = 0;

    key[source] = 0;
    PQ.push(make_pair(key[source], source));

    while (!PQ.empty()) {
        u = PQ.top().second;
        PQ.pop();

        inMST[u] = true;
        //printf("u = %d\n", u);
        _count++;

        for (v = 0; v < nodes; v++) {
            double w = matrix[u][v];

            if (!inMST[v] && key[v] > w) {
                key[v] = w;
                PQ.push(make_pair(key[v], v));
                parent[v] = u;
                last = v;
                //ans += w;

                //printf("v = %d count = %d\n", v, _count);
                //for (int k = 0; k < nodes; k++) {
                    //printf("key[%d] = %.2lf\n", k, key[k]);
                //}
            }
        }

        /*
        if (_count == nodes) {
            break;
        }
        */
    }

    for (int i = 0; i < nodes; i++) {
        ans += key[i];
    }

    return ans;
}

void printMatrix(int nodes)
{
    cout << " \t";
    for (int i = 0; i < nodes; i++) {
        cout << i << "\t";
    }
    cout << "\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << "\t";
        for (int j = 0; j < nodes; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}
