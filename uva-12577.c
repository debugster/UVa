#include <stdio.h>
#include <string.h>

int main()
{
    char input[10];
    int i = 1;
    while (scanf("%s", input) && strcmp(input, "*")) {
        if (!strcmp(input, "Hajj"))
            printf("Case %d: Hajj-e-Akbar\n", i);
        else if (!strcmp(input, "Umrah"))
            printf("Case %d: Hajj-e-Asghar\n", i);
        i++;
    }
    return 0;
}
