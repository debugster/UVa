#include <bits/stdc++.h>

using namespace std;

deque<int>Left;
deque<int>Right;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);

    int test, L, m, i, LenCar, passCount, currentLoad, temp;
    char pos[10];
    bool Loaded;

    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &L, &m);

        L *= 100;
        for (i = 1; i <= m; i++) {
            scanf("%d %s", &LenCar, pos);

            if (pos[0] == 'l') {
                Left.push_back(LenCar);
            }
            else {
                Right.push_back(LenCar);
            }
        }

        passCount = 0;
        while (m > 0) {

            currentLoad = 0;
            Loaded = false;
            while (1) {
                if (Left.size() > 0) {
                    if (currentLoad + Left.front() <= L) {
                        currentLoad += Left.front();
                        Left.pop_front();
                        m--;
                    }
                    else {
                        Loaded = true;
                    }
                }

                if (Loaded == false && Left.size() != 0) {
                    continue;
                }
                else if (Right.size() > 0 || Loaded == true || currentLoad != 0) {
                    passCount++;
                    break;
                }

                if (m == 0) {
                    break;
                }
            }

            //printf("Left m = %d\n", m);

            currentLoad = 0;
            Loaded = false;
            while (1) {
                if (Right.size() > 0) {
                    if (currentLoad + Right.front() <= L) {
                        currentLoad += Right.front();
                        Right.pop_front();
                        m--;
                    }
                    else {
                        Loaded = true;
                    }
                }

                if (Loaded == false && Right.size() != 0) {
                    continue;
                }
                else if (Left.size() > 0 || Loaded == true || currentLoad != 0) {
                    passCount++;
                    break;
                }

                if (m == 0) {
                    break;
                }
            }

            //printf("Right m = %d\n", m);
        }
        printf("%d\n", passCount);
        //Left.clear();
        //Right.clear();
    }

    return 0;
}
