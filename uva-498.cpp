#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

vector<long long>allC;
vector<long long>allX;
long long P[MAX];

void extractIntegerWords(string str, vector<long long> &v)
{
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    v.clear();
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
            //cout << found << " " << sizeof(found) << "\n";
            v.push_back(found);

        /* To save from space at the end of string */
        temp = "";
    }
    //cout << "##" << "\n";
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    bool _eof = false;
    char ch;
    long long c, x, i, j, n;
    string strC, strX;
    char s1[MAX], s2[MAX];

    while (gets(s1)) {
        gets(s2);

        strC = s1;
        strX = s2;

        //cout << strC << "\n" << strX << "\n";


        extractIntegerWords(strC, allC);
        extractIntegerWords(strX, allX);

        /*
        for (i = 0; i < allC.size(); i++) {
            printf("%d ", allC[i]);
        }
        printf("\n");
        for (i = 0; i < allX.size(); i++) {
            printf("%d ", allX[i]);
        }
        printf("\n");
        */

        n = allC.size() - 1;
        reverse(allC.begin(), allC.end());
        P[n] = allC[n];
        for (j = 0; j < allX.size(); j++) {
            x = allX[j];
            for (i = n - 1; i >= 0; i--) {
                P[i] = P[i + 1] * x + allC[i];
            }
            printf("%lld", P[0]);
            if (j == allX.size() - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }



    return 0;
}
