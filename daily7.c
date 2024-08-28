#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int process_test_case(void);

int main (int argc, char* argv[])
{

    int n;
    int i;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        if (process_test_case())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
   
    return 0;
}

int process_test_case(void)
{
    int i;
    int check;
    char checks;
    Status stat;
    char temp;
    STACK init = stack_init_default();
    scanf("%c", &temp);
    while (temp != '\0')
    {
        switch (temp)
        {
        case '(':
        case '[':
        case '{':
            check = stack_push(init, temp);
            if (check < 1)
            {
                printf("Push couldn't complete\n");
                exit(1);
            }
            scanf("%c", &temp);
            break;
        case ')':
            checks = stack_top(init, &stat);

            switch (checks)
            {
            case '(':
                stat = stack_pop(init);
                if (stat == FAILURE)
                {
                    return 1;
                }
                scanf("%c", &temp);
                break;
            default:
                stack_destroy(&init);
                STACK init = stack_init_default();
                scanf("%c", &temp);
                return 0;
                break;
            }
            break;
        case ']':
            checks = stack_top(init, &stat);

            switch (checks)
            {
            case '[':
                stat = stack_pop(init);
                if (stat == FAILURE)
                {
                    return 1;
                }
                scanf("%c", &temp);
                break;
            default:
                stack_destroy(&init);
                STACK init = stack_init_default();
                scanf("%c", &temp);
                return 0;
                break;
            }
            break;
        case '}':
            checks = stack_top(init, &stat);

            switch (checks)
            {
            case '{':
                stat = stack_pop(init);
                if (stat == FAILURE)
                {
                    return 1;
                }
                scanf("%c", &temp);
                break;
            default:
                stack_destroy(&init);
                STACK init = stack_init_default();
                scanf("%c", &temp);
                return 0;
                break;
            }
            break;
        }
    }

    return 0;
}

