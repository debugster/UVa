#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n[9], coeff[9][2], i, j, power;

    while (scanf("%d", &n[0]) != EOF) {
        /// Scanning the coefficients
        for (i = 1; i < 9; i++) {
            scanf("%d", &n[i]);
        }

        /// Putting only non-zero coefficients with there respective degrees inside coeff[][]
        /// coeff[non-zero values][respective degree]
        /// Variable "j" keeps the total number of non-zero values
        for (i = 0, j = 0, power = 8; i < 9; i++, power--) {
            if (n[i] != 0) {
                coeff[j][0] = n[i];
                coeff[j][1] = power;
                j++;
            }
        }

        /// If j is equal to 0, that means there is no non-zero coefficient
        /// So the polynomial expression is 0
        if (j == 0) {
            printf("0");
        }
        /// If there is only one non-zero coefficient,
        /// There will be no "+" or "-" operator
        else if (j == 1) {

            /// If that only non-zero coefficient's degree is greater than 0,
            /// Then "x" must be printed out like x^degree
            if (coeff[0][1] > 0) {

                /// If the coefficient is 1, then it should not be printed out
                /// Just printing x rather than 1x
                if (coeff[0][0] == 1) {
                    printf("x");
                }
                /// If the coefficient is -1, then it should not be printed out
                /// Just printing -x rather than -1x
                else if (coeff[0][0] == -1) {
                    printf("-x");
                }
                /// If the coefficient is any other rather than 1 and -1,
                /// then it should be printed out as Cx,
                /// where C is the respective coefficient
                else {
                    printf("%dx", coeff[0][0]);
                }

                /// If the degree is greater than 1,
                /// only then the degree should be printed out
                /// Because, we don't need to print 5x as 5x^1
                if (coeff[0][1] > 1) {
                    printf("^%d", coeff[0][1]);
                }
            }
            /// If that only non-zero coefficient's degree is 0,
            /// that means, it is the last constant term
            /// So, the degree of "x" is zero there
            /// Hence, we have to print only the constant coefficient with its sign
            else {
                printf("%d", coeff[0][0]);
            }
        }
        /// If there is more than one non-zero coefficient,
        /// There will be "+" or "-" operator(s)
        else {
            /// Indexing from the first element to the second last element
            /// Because, last element could be constant coefficient
            /// Hence it should be taken care of in other way
            for (i = 0; i < j - 1; i++) {

                /// If i == 0, that means, it is the first non-zero coefficient
                if (i == 0) {
                    /// If the coefficient is 1, then it should not be printed out
                    /// Just printing x rather than 1x
                    if (coeff[i][0] == 1) {
                        printf("x");
                    }
                    /// If the coefficient is -1, then it should not be printed out
                    /// Just printing -x rather than -1x
                    else if (coeff[i][0] == -1) {
                        printf("-x");
                    }
                    /// If the coefficient is any other rather than 1 and -1,
                    /// then it should be printed out as Cx,
                    /// where C is the respective coefficient
                    else {
                        printf("%dx", coeff[i][0]);
                    }
                }
                /// If i != 0, that means it is not the first non-zero coefficient
                else {
                    /// Since operator between two adjacent terms is printed separately,
                    /// Hence, we should just print the numerical part of the respective coefficient
                    /// without its sign
                    /// So, if the absolute value of the coefficient is 1,
                    /// Then printing "x" instead of "1x"
                    if (abs(coeff[i][0]) == 1) {
                        printf("x");
                    }
                    /// And if the absolute value of the coefficient is anything rather than 1,
                    /// Then printing "Cx", where C is the absolute value of the respective coefficient
                    else if (abs(coeff[i][0]) > 1) {
                        printf("%dx", abs(coeff[i][0]));
                    }
                }

                /// Now it's time to print the degree
                /// The respective degree should be printed out only when it is greater than 1
                /// Because, we must not print "5x" as "5x^1" or "7" as "7x^0"
                if (coeff[i][1] > 1) {
                    printf("^%d", coeff[i][1]);
                }

                /// It's time to print the operator i.e "+" or "-"
                /// Operator printing depends on the next non-zero coefficient
                /// If the next (that means (i + 1)th) non-zero coefficient is greater than 0,
                /// then the operator must be "+"
                if (coeff[i + 1][0] > 0) {
                    printf(" + ");
                }
                /// If the next (that means (i + 1)th) non-zero coefficient is less than 0,
                /// then the operator must be "-"
                else if (coeff[i + 1][0] < 0) {
                    printf(" - ");
                }
            }

            /// Now it's time to handle the last non-zero coefficient i.e. (j - 1)th element of the array
            /// If the degree of the last non-zero coefficient is greater than 0,
            /// then we must print "x"
            if (coeff[j - 1][1] > 0) {

                /// So, if the absolute value of the coefficient is 1,
                /// Then printing "x" instead of "1x"
                if (abs(coeff[j - 1][0]) == 1) {
                    printf("x");
                }
                /// And if the absolute value of the coefficient is anything rather than 1,
                /// Then printing "Cx", where C is the absolute value of the respective coefficient
                else if (abs(coeff[j - 1][0]) > 1) {
                    printf("%dx", abs(coeff[j - 1][0]));
                }

                /// The respective degree should be printed out only when it is greater than 1
                /// Because, we must not print "5x" as "5x^1" or "7" as "7x^0"
                if (coeff[j - 1][1] > 1) {
                    printf("^%d", coeff[j - 1][1]);
                }
            }
            /// If the degree of the last non-zero coefficient is equal to 0,
            /// that means, it is the last constant term
            /// So, the degree of "x" is zero there
            /// Hence, we have to print only the absolute value of that constant coefficient
            else {
                printf("%d", abs(coeff[j - 1][0]));
            }
        }
        printf("\n");
    }

    return 0;
}

