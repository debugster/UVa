#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char text[1000];
    int Len, i;
    bool toggle;

    toggle = true;
    while (gets(text)) {

        Len = strlen(text);

        for (i = 0; i < Len; ) {
            if (text[i] == '\\') {

                switch (text[i + 1]) {
                    case '*':
                        if (toggle == true) {
                            toggle = false;
                        }
                        else {
                            toggle = true;
                        }

                        i += 2;
                        if (i < Len) {
                            while (true) {
                                if (text[i] == '\\' && text[i + 1] == '*') {
                                    i += 2;
                                    //toggle = true;
                                    if (toggle == true) {
                                        toggle = false;
                                    }
                                    else {
                                        toggle = true;
                                    }
                                    break;
                                }
                                if (i < Len) {
                                    printf("%c", text[i]);
                                }
                                i++;
                            }
                        }
                        break;

                    case '\\':
                        if (toggle == true) {
                            i++;
                            printf("%c", text[i]);
                            i++;
                        }
                        else {
                            printf("%c", text[i]);
                            i++;
                            printf("%c", text[i]);
                            i++;
                        }
                        break;
                    case 'b':
                    case 'i':
                        if (toggle == true) {
                            i += 2;
                        }
                        else {
                            printf("%c", text[i]);
                            i++;
                            printf("%c", text[i]);
                            i++;
                        }

                        break;

                    case 's':
                        if (toggle == true) {
                            i += 2;
                            while (text[i] == '.' || (text[i] >= '0' && text[i] <= '9')) {
                                i++;
                            }
                        }
                        else {
                            printf("%c", text[i]);
                            i++;
                            printf("%c", text[i]);
                            i++;
                        }

                        break;

                    default:
                        i++;
                        printf("%c", text[i]);
                        i++;
                        break;
                }
            }
            else {
                printf("%c", text[i]);
                i++;
            }
        }
        printf("\n");
    }

    return 0;
}


