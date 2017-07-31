#include <bits/stdc++.h>

using namespace std;

char INFIX[100][20];
vector<char *>POSTFIX;
vector<char>STACK;

void charToString(char c, char *s);
void pushOperator(char c);
void popOperator(char c);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int Len, i, test, t;
    char c[20], dump;

    scanf("%d", &test);
    dump = getchar();
    dump = getchar();

    for (t = 1; t <= test; t++)
    {
        Len = 0;
        while (gets(c)) {

            if (strcmp(c, "\0") == 0) {
                break;
            }
            else {
                strcpy(INFIX[Len++], c);
            }
        }

        strcpy(INFIX[Len++], ")\0");

        /*for (i = 0; i < Len; i++) {
            printf("%s", INFIX[i]);
        }
        printf("\n");*/

        STACK.push_back('(');

        for (i = 0; i < Len; i++)
        {

            if (!strcmp("(", INFIX[i]))
            {
                STACK.push_back('(');
            }
            else if (!strcmp(")", INFIX[i]))
            {
                while (STACK[STACK.size() - 1] != '(')
                {
                    pushOperator(STACK[STACK.size() - 1]);
                    STACK.pop_back();
                }
                /// Removing '('
                STACK.pop_back();
            }
            else if (!strcmp("+", INFIX[i]))
            {
                popOperator('+');
            }
            else if (!strcmp("-", INFIX[i]))
            {
                popOperator('-');
            }
            else if (!strcmp("*", INFIX[i]))
            {
                popOperator('*');
            }
            else if (!strcmp("/", INFIX[i]))
            {
                popOperator('/');
            }
            /// Otherwise, its the Operand
            else
            {
                POSTFIX.push_back(INFIX[i]);
            }
        }

        for (i = 0; i < POSTFIX.size(); i++)
        {
            printf("%s", POSTFIX[i]);
        }

        if (t != test) {
            printf("\n\n");
        }

        POSTFIX.clear();
        STACK.clear();
    }
    printf("\n");
    return 0;
}

void pushOperator(char c)
{
    switch (c)
    {
    case '+':
        POSTFIX.push_back("+\0");
        break;

    case '-':
        POSTFIX.push_back("-\0");
        break;

    case '*':
        POSTFIX.push_back("*\0");
        break;

    case '/':
        POSTFIX.push_back("/\0");
        break;
    }
}

void popOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        while (STACK[STACK.size() - 1] != '(')
        {
            pushOperator(STACK[STACK.size() - 1]);
            STACK.pop_back();
        }
        break;
    case '*':
    case '/':
        while ((STACK[STACK.size() - 1] == '/' || STACK[STACK.size() - 1] == '*') && STACK[STACK.size() - 1] != '(')
        {
            pushOperator(STACK[STACK.size() - 1]);
            STACK.pop_back();
        }
        break;
    }

    STACK.push_back(c);
}
