#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int data[MAX][MAX];

int findMaxSum(int n);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, j;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &data[i][j]);
            }
        }
        printf("%d\n", findMaxSum(n));
    }

    return 0;
}

int findMaxSum(int n)
{
    int *tempRow = new int[n];
    int row, x, i, temp, sum, maxSum;

    maxSum = INT_MIN;

    for (row = 0; row < n; row++) {
        for (i = 0; i < n; i++) {
            tempRow[i] = 0;
        }

        for (x = row; x < n; x++) {
            sum = INT_MIN;
            temp = 0;

            for (i = 0; i < n; i++) {
                tempRow[i] += data[x][i];
                temp += tempRow[i];

                if (temp > sum) {
                    sum = temp;
                }

                if (temp < 0) {
                    temp = 0;
                }
            }

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    delete [] tempRow;
    return maxSum;
}
