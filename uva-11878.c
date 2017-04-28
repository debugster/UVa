#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int a, b, c_num, count = 0;
    char op, c[10];

    while (scanf("%d%c%d=%s", &a, &op, &b, &c) != EOF) {


        if (c[0] != '?') {
            c_num = atoi(c);
            switch (op) {
                case '+':
                    if (a + b == c_num) {
                        count++;
                    }
                    break;
                case '-':
                    if (a - b == c_num) {
                        count++;
                    }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
