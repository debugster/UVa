#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char year[100000];
int Length;

int divisible_by_3();
int divisible_by_4();
int divisible_by_5();
int divisible_by_11();
int divisible_by_15();
int divisible_by_55();
int divisible_by_100();
int divisible_by_400();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int ordinary, leap, i = 1;

    while (scanf("%s", year) != EOF) {
        Length = strlen(year);

        ordinary = 1;
        leap = 0;

        if (i > 1) {
            printf("\n");
        }

        if (divisible_by_400() || divisible_by_4() && !divisible_by_100()) {
            printf("This is leap year.\n");
            ordinary = 0;
            leap = 1;
        }

        if (divisible_by_15()) {
            printf("This is huluculu festival year.\n");
            ordinary = 0;
        }

        if (leap && divisible_by_55()) {
            printf("This is bulukulu festival year.\n");
            ordinary = 0;
        }

        if (ordinary) {
            printf("This is an ordinary year.\n");
        }

        i++;
    }

    return 0;
}

int divisible_by_3()
{
    int sum = 0, result = 0, i;

    for (i = 0; i < Length; i++) {
        sum += year[i];
    }

    if (sum % 3 == 0) {
        result = 1;
    }

    return result;
}

int divisible_by_4()
{
    int sum, result = 0;

    sum = ((year[Length - 2] - 48) * 10) + (year[Length - 1] - 48);

    if (sum % 4 == 0) {
        result = 1;
    }

    return result;
}

int divisible_by_5()
{
    int result = 0;

    if (year[Length - 1] == '0' || year[Length - 1] == '5') {
        result = 1;
    }

    return result;
}

int divisible_by_11()
{
    int odd_sum = 0, even_sum = 0, sum, i, result = 0;

    for (i = 0; i < Length; i++) {
        if ((i + 1) % 2 == 1) {
            odd_sum += (int) year[i] - 48;
        }
        else {
            even_sum += (int) year[i] - 48;
        }
    }

    sum = abs(odd_sum - even_sum);

    if (sum % 11 == 0) {
        result = 1;
    }

    return result;
}

int divisible_by_15()
{
    int result = 0;

    if (divisible_by_3() == 1 && divisible_by_5() == 1) {
        result = 1;
    }

    return result;
}

int divisible_by_55()
{
    int result = 0;

    if (divisible_by_5() == 1 && divisible_by_11() == 1) {
        result = 1;
    }

    return result;
}

int divisible_by_100()
{
    int result = 0;

    if (year[Length - 2] == '0' && year[Length - 1] == '0') {
        result = 1;
    }

    return result;
}

int divisible_by_400()
{
    int sum, result = 0;

    sum = ((year[Length - 4] - 48) * 1000) + ((year[Length - 3] - 48) * 100) + ((year[Length - 2] - 48) * 10) + (year[Length - 1] - 48);

    if (sum % 400 == 0) {
        result = 1;
    }

    return result;
}
