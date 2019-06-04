#include "../include/push_swap.h"
#include <stdio.h>

void        print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

int         isNumber(char *arg)
{
    while   (*arg)
        if (*arg > '0' && *arg < '9')
            arg++;
        else
            return(0);        
    return (1);
}

int             isUnique(struct s_stack *stck, int num)
{
    t_stack *temp;

    temp = stck;

    while (!isEmpty(temp))
    {
        if (num == peek(temp))
            return (0);
        temp = temp->top->next;
    }
    return (1);
}

t_stack         *push_args(int ac, char **av)
{
    int i;
    t_stack     *stck;
    int num;
    stck = init();
    i = ac - 1;
    while (i > 0)
    {
        if (!isNumber(av[i]))
            print_error();
        num = ft_atoi(av[i]);
        if (!isUnique(stck, num))
            print_error();
        push(stck, num);
        i--;
    }
    return (stck);
}

int         main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
    int i = 0;

    stack_b = init();
    stack_a = push_args(ac, av);
    while (!isEmpty(stack_a))
    {
        printf("Number #%d: %d\n", i, peek(stack_a));
        pop(stack_a);
    }
    return (0);
}