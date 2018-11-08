#include <bits/stdc++.h>

using namespace std;

struct proposalBrand
{
    char brandName[100];
    int metRequirement;
    double totalPrice;
    double compliance;
};

bool compare(proposalBrand x, proposalBrand y)
{
    if (x.compliance == y.compliance) {
        return x.totalPrice < y.totalPrice;
    }

    return x.compliance > y.compliance;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, p, i, j, testCase = 1;
    char str[100];
    proposalBrand *brands;

    while (scanf("%d%d", &n, &p), (n && p)) {
        getchar();
        for (i = 1; i <= n; i++) {
            gets(str);
        }

        brands = (proposalBrand *) malloc(p * sizeof(proposalBrand));

        for (i = 0; i < p; i++) {
            gets(brands[i].brandName);
            scanf("%lf%d", &brands[i].totalPrice, &brands[i].metRequirement);
            getchar();
            brands[i].compliance = (brands[i].metRequirement * 1.0) / n;
            for (j = 1; j <= brands[i].metRequirement; j++) {
                gets(str);
            }
        }

        sort(brands, brands + p, compare);

        if (testCase > 1) {
            printf("\n");
        }
        printf("RFP #%d\n%s\n", testCase++, brands[0].brandName);

        free(brands);
    }

    return 0;
}

