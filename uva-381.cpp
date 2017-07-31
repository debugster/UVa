#include <bits/stdc++.h>

using namespace std;

int **test, *bonus, *absent;
double *average, *adjustedAverage;
char *grade, *adjustedGrade;

int S;
int T;
double mean;
double SD;
double SDaboveMean;
double SDbelowMean;
double gradeFinalOutput;

void allocateData(int s, int t);
int minimumMarks(int index, int t);
void countSD();
void countGrade();
void gradeAdjust();
void countFinalOutput();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int N;
    int i, j, sum;

    printf("MAKING THE GRADE OUTPUT\n");

    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &S, &T);

        allocateData(S, T);

        mean = 0;
        for (i = 0; i < S; i++) {
            sum = 0;
            for (j = 0; j < T; j++) {
                scanf("%d", &test[i][j]);
                sum += test[i][j];
            }

            if (T > 2) {
                sum -= minimumMarks(i, T);
                average[i] = (double) sum / (T - 1);
            }
            else {
                average[i] = (double) sum / T;
            }

            mean += average[i];

            scanf("%d%d", &bonus[i], &absent[i]);

            adjustedAverage[i] = average[i] + (int) (bonus[i] / 2) * 3;
        }

        mean /= S;
        countSD();
        //printf("%.1lf %.1lf\n", mean, SD);

        SDaboveMean = mean + SD;
        SDbelowMean = mean - SD;

        countGrade();
        gradeAdjust();

        /*
        for (i = 0; i < S; i++) {
            sum = 0;
            for (j = 0; j < T; j++) {
                printf("%d ", test[i][j]);
            }

            printf("%d %d %.1lf %.1lf %c %c\n", bonus[i], absent[i], average[i], adjustedAverage[i], grade[i], adjustedGrade[i]);
        }
        */

        countFinalOutput();
        printf("%.1lf\n", gradeFinalOutput);

    }

    printf("END OF OUTPUT\n");

    return 0;
}

void allocateData(int s, int t)
{
    int i;

    test = (int **) malloc(s * sizeof(int *));
    for (i = 0; i < s; i++) {
        test[i] = (int *) malloc(t * sizeof(int));
    }

    bonus = (int *) malloc(s * sizeof(int));
    absent = (int *) malloc(s * sizeof(int));

    average = (double *) malloc(s * sizeof(double));
    adjustedAverage = (double *) malloc(s * sizeof(double));

    grade = (char *) malloc(s * sizeof(char));
    adjustedGrade = (char *) malloc(s * sizeof(char));
}

int minimumMarks(int index, int t)
{
    int minimum = 101, a;

    for (a = 0; a < t; a++) {
        if (test[index][a] < minimum) {
            minimum = test[index][a];
        }
    }

    return minimum;
}

void countSD()
{
    double sum = 0;
    int i;

    for (i = 0; i < S; i++) {
        sum += pow((average[i] - mean), 2);
    }

    sum /= S;
    SD = sqrt(sum);
}

void countGrade()
{
    int i;

    for (i = 0; i < S; i++) {
        if (adjustedAverage[i] >= SDaboveMean) {
            grade[i] = 'A';
        }
        else if (adjustedAverage[i] >= mean && adjustedAverage[i] < SDaboveMean) {
            grade[i] = 'B';
        }
        else if (adjustedAverage[i] >= SDbelowMean && adjustedAverage[i] < mean) {
            grade[i] = 'C';
        }
        else if (adjustedAverage[i] < SDbelowMean) {
            grade[i] = 'D';
        }
        else {
            grade[i] = 'F';
        }
    }
}

void gradeAdjust()
{
    int i, value;

    for (i = 0; i < S; i++) {
        adjustedGrade[i] = grade[i];

        if (absent[i] == 0) {
            /// Perfect student with zero absence
            /// Gains one letter grade
            /// So, decreasing ASCII value of the grade
            adjustedGrade[i]--;
        }
        else {
            value = absent[i] / 4;

            /// Loses one letter grade for 4 absences
            /// Hence total grade loss is equal to "value"
            /// So, increasing ASCII value of the grade
            adjustedGrade[i] += value;
        }

        /// If the adjusted letter grade has less ASCII value than 'A', set it to 'A'
        /// Because, no letter grade is possible greater than "A"
        /// Else if adjusted letter grade has greater ASCII value than 'D', set it to 'F'
        /// Because, no letter grade is possible less than "F" (Grade "E" is also not possible)

        if (adjustedGrade[i] < 'A') {
            adjustedGrade[i] = 'A';
        }
        else if (adjustedGrade[i] > 'D') {
            adjustedGrade[i] = 'F';
        }
    }
}

void countFinalOutput()
{
    int i;

    gradeFinalOutput = 0;
    for (i = 0; i < S; i++) {
        switch (adjustedGrade[i]) {
            case 'A':
                gradeFinalOutput += 4;
                break;

            case 'B':
                gradeFinalOutput += 3;
                break;

            case 'C':
                gradeFinalOutput += 2;
                break;

            case 'D':
                gradeFinalOutput += 1;
                break;
        }
    }

    gradeFinalOutput /= S;
}
