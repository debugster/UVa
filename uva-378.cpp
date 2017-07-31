#include <bits/stdc++.h>

using namespace std;

int X[5], Y[5];
double SLOPE1, SLOPE2;
double A1, A2, B1, B2, C1, C2; /// Coefficients of the equations (Ax + By + C = 0) of straight lines
double A, B, C; /// Keeping ratios of the coefficients
double posX, posY; /// Keeping intersecting points
bool infiniteSlope1, infiniteSlope2;

bool samePoints();
void calculateSlope();
void calculateCoeff();
void solveEquation();

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    /// 5 5 10 10 20 20 5 5


    int N, i;

    printf("INTERSECTING LINES OUTPUT\n");

    scanf("%d", &N);
    while (N--) {
        for (i = 1; i <= 4; i++) {
            scanf("%d%d", &X[i], &Y[i]);
        }

        if (samePoints()) {
            printf("LINE\n");
            continue;
        }

        calculateSlope();
        //printf("%.4lf %.4lf\n", SLOPE1, SLOPE2);

        /// If both slopes are infinite, they are either parallel or the same line
        if (infiniteSlope1 == true && infiniteSlope2 == true) {
            /// If X1 and X3 are equal, then they are the same line
            if (X[1] == X[3] || X[1] == X[4]) {
                printf("LINE\n");
            }
            /// Otherwise, they are parallel
            else {
                printf("NONE\n");
            }

            /// No further calculation needed
            continue;
        }
        /// If slope of the 1st line is infinite but 2nd is not
        else if (infiniteSlope1 == true || infiniteSlope2 == true) {
            calculateCoeff();
            solveEquation();

            printf("POINT %.2lf %.2lf\n", posX, posY);

            /// No further calculation needed
            continue;

        }

        /// If slope of the two lines are equal,
        /// Either they are parallel or the same line
        if (fabs(SLOPE1 - SLOPE2) < 0.000001) {
            calculateCoeff();

            /// Calculating ratios of the coefficients
            A = A1 / A2;
            B = B1 / B2;
            C = C1 / C2;

            /// If first two points are same as second two point,
            /// That means, they represent same line
            /// But, while calculating ratios of their coefficients,
            /// Any of three ratios A or B or C might have infinite value (i.e. 0/0)
            /// That's why, at first, we have to check whether the given pair points are same or not
            /// If that is true, then obviously they are the same line
            /// Hence, output will be "LINE"
            if (fabs(A1 - A2) < 0.000001 && fabs(B1 - B2) < 0.000001 && fabs(C1 - C2) < 0.000001) {
                printf("LINE\n");
            }

            /// If the ratios of the coefficients are equal,
            /// Then they are the same line
            else if (fabs(A - B) < 0.000001 && fabs(B - C) < 0.000001) {
                printf("LINE\n");
            }
            /// If the ratios A and B are equal and C1 is equal to C2,
            /// They are the same line
            else if (fabs(A - B) < 0.000001 && fabs(C1 - C2) < 0.000001) {
                printf("LINE\n");
            }
            /// Otherwise, they are parallel
            else {
                printf("NONE\n");
            }
        }
        /// If slope of the two lines are not equal,
        /// they will intersect each other
        else {
            calculateCoeff();
            solveEquation();

            printf("POINT %.2lf %.2lf\n", posX, posY);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}

bool samePoints()
{
    bool same = false;

    if (X[1] == X[3] && Y[1] == Y[3]) {
        if (X[2] == X[4] && Y[2] == Y[4]) {
            same = true;
        }
    }
    else if (X[1] == X[4] && Y[1] == Y[4]) {
        if (X[2] == X[3] && Y[2] == Y[3]) {
            same = true;
        }
    }

    return same;
}

void calculateSlope()
{
    /// Slope of a straight line is infinite when X1 is equal to X2,
    /// Where two points on the straight line are (X1, Y1) and (X2, Y2)

    if (X[2] == X[1]) {
        infiniteSlope1 = true;
    }
    else {
        SLOPE1 = (double) (Y[2] - Y[1]) / (double) (X[2] - X[1]);
        infiniteSlope1 = false;
    }

    if (X[4] == X[3]) {
        infiniteSlope2 = true;
    }
    else {
        SLOPE2 = (double) (Y[4] - Y[3]) / (double) (X[4] - X[3]);
        infiniteSlope2 = false;
    }
}

void calculateCoeff()
{
    /// Calculating coefficients for the 1st straight line
    A1 = Y[1] - Y[2];
    B1 = X[2] - X[1];
    C1 = (X[1] * Y[2]) - (X[2] * Y[1]);

    /// Calculating coefficients for the 2nd straight line
    A2 = Y[3] - Y[4];
    B2 = X[4] - X[3];
    C2 = (X[3] * Y[4]) - (X[4] * Y[3]);

    //printf("%.2lf %.2lf %.2lf\n", A1, B1, C1);
    //printf("%.2lf %.2lf %.2lf\n", A2, B2, C2);
}

/// This function will solve the equations of two straight lines
/// using Cross-multiplication method
/// And keeps the intersecting points at (posX, posY)
void solveEquation()
{
    /// Let,
    /// Equation 1 : A1x + B1y + C1 = 0
    /// Equation 2 : A2x + B2y + C2 = 0

    double localX = 0, localY = 0, localC = 0;

    localX = B1 * C2 - B2 * C1;
    localY = A2 * C1 - A1 * C2;
    localC = A1 * B2 - A2 * B1;

    //printf("%.2lf %.2lf %.2lf\n", localX, localY, localC);

    posX = localX / localC;
    posY = localY / localC;

    /// 0/-2 produces -0
    /// Thats why, making -0 as 0
    if (posX == 0.000000) {
        posX = 0;
    }
    if (posY == 0.000000) {
        posY = 0;
    }
}
