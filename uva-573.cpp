#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /// Critical TC
    /// 56 3 1 5

    int h, u, d, f, day;
    double climed, factor, prev, now;

    while (scanf("%d%d%d%d", &h, &u, &d, &f)) {
        if (!h) {
            break;
        }

        climed = 0;
        day = 0;
        factor = u * (f / 100.0);
        prev = u + factor;

        //printf("Day\tI.H\tD.C\tH.Climb\t\tH.Slide\n");

        while (true) {
            day++;
            now = prev - factor;

            //printf("%d\t%.2lf\t%.2lf\t", day, climed, now);

            /// It does not climb negative distance
            /// Hence, if distance to be climbed today is negative,
            /// making it 0 since snail does not climb at all that day
            if (now < 0.0) {
                now = 0;
            }

            climed += now;

            //printf("%.2lf\t\t", climed);

            if (climed > h) {
                //printf("\n\nsuccess on day %d\n", day);
                printf("success on day %d\n", day);
                break;
            }

            climed -= d;

            //printf("%.2lf\n", climed);

            if (climed < 0.0) {
                //printf("\n\nfailure on day %d\n", day);
                printf("failure on day %d\n", day);
                break;
            }

            prev = now;
        }
    }

    return 0;
}

