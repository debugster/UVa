/// RT : 0.550

#include <bits/stdc++.h>

using namespace std;

int factors[1000];
int top;

void initialize();
void push(int n);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int factorSize;
    int n, i, limit;

    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }

        if (n == -1) {
            printf("-1 = -1 x \n");
            continue;
        }
        else if (n == 1) {
            printf("1 = \n");
            continue;
        }

        initialize();

        printf("%d = ", n);

        if (n < 0) {
            printf("-1 x ");
            n *= -1;
        }

        limit = sqrt(n);
        for (i = 2; i <= limit; ) {
            if (i > n) {
                break;
            }

            if (n % i == 0) {
                while (n % i == 0) {
                    push(i);
                    n /= i;
                }
            }

            if (i == 2) {
                i++;
            }
            else {
                i += 2;
            }
        }
        if (n != 1) {
            push(n);
        }

        for (i = 0; i <= top - 1; i++) {
            printf("%d x ", factors[i]);
        }
        printf("%d\n", factors[i]);
    }
    return 0;
}

void initialize()
{
    top = -1;
}

void push(int n)
{
    factors[++top] = n;
}
