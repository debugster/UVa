#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

void getValueFromString(double &data, char *str);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, i, j, k, Len, foundCount, powerPrefix, voltagePrefix, currentPrefix;
    double power, voltage, current;
    bool powerFound, voltageFound, currentFound;
    char text[MAX + 5], p[100], v[100], c[100];

    scanf("%d", &test);
    getchar();
    for (t = 1; t <= test; t++) {
        gets(text);
        Len = strlen(text);

        foundCount = 0;
        powerPrefix = voltagePrefix = currentPrefix = 0;
        power = voltage, current = 0.0;
        powerFound = voltageFound = currentFound = false;
        for (i = 0; i < Len; i++) {
            if (text[i] == 'P' && text[i + 1] == '=') {
                powerFound = true;
                for (k = 0, j = i + 2; ; k++, j++) {
                    if (text[j] == 'W') {
                        break;
                    }
                    p[k] = text[j];
                }
                i = j;
                p[k] = '\0';
                foundCount++;
            }
            else if (text[i] == 'U' && text[i + 1] == '=') {
                voltageFound = true;
                for (k = 0, j = i + 2; ; k++, j++) {
                    if (text[j] == 'V') {
                        break;
                    }
                    v[k] = text[j];
                }
                i = j;
                v[k] = '\0';
                foundCount++;
            }
            else if (text[i] == 'I' && text[i + 1] == '=') {
                currentFound = true;
                for (k = 0, j = i + 2; ; k++, j++) {
                    if (text[j] == 'A') {
                        break;
                    }
                    c[k] = text[j];
                }
                i = j;
                c[k] = '\0';
                foundCount++;
            }

            if (foundCount == 2) {
                break;
            }
        }

        printf("Problem #%d\n", t);
        if (powerFound && voltageFound) {
            getValueFromString(power, p);
            getValueFromString(voltage, v);
            current = power / voltage;
            printf("I=%.2lfA\n", current);
        }
        else if (powerFound && currentFound) {
            getValueFromString(power, p);
            getValueFromString(current, c);
            voltage = power / current;
            printf("U=%.2lfV\n", voltage);
        }
        else {
            getValueFromString(current, c);
            getValueFromString(voltage, v);
            power = voltage * current;
            printf("P=%.2lfW\n", power);
        }
        printf("\n");
    }

    return 0;
}

void getValueFromString(double &data, char *str)
{
    int Len;
    double prefix;

    Len = strlen(str);

    switch (str[Len - 1]) {
        case 'm':
            prefix = 0.001;
            str[Len - 1] = '\0';
            break;

        case 'k':
            prefix = 1000;
            str[Len - 1] = '\0';
            break;

        case 'M':
            prefix = 1000000;
            str[Len - 1] = '\0';
            break;

        default:
            prefix = 1.0;
            break;
    }
    sscanf(str, "%lf", &data);
    data *= prefix;
}
