#include <bits/stdc++.h>

using namespace std;

stack<char>STACK;
void clearStack();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /// (())()(])

    int test, Len, i;
    char text[200], dump;
    bool balanced;

    scanf("%d", &test);
    dump = getchar();
    while (test--) {
        clearStack();

        gets(text);
        Len = strlen(text);

        balanced = true;
        for (i = 0; i < Len; i++) {
            if (text[i] == '[' || text[i] == '(') {
                STACK.push(text[i]);
            }
            else if (text[i] == ')') {
                if (!STACK.empty()) {
                    if (STACK.top() == '(') {
                        STACK.pop();
                    }
                    else {
                        balanced = false;
                    }
                }
                else {
                    balanced = false;
                }
            }
            else if (text[i] == ']') {
                if (!STACK.empty()) {
                    if (STACK.top() == '[') {
                        STACK.pop();
                    }
                    else {
                        balanced = false;
                    }
                }
                else {
                    balanced = false;
                }
            }

            if (!balanced) {
                break;
            }
        }

        if (balanced && STACK.empty()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}

void clearStack()
{
    while (!STACK.empty()) {
        STACK.pop();
    }
}
