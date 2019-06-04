#include "../include/push_swap.h"
#include <stdio.h>
commands *g_func[11] = {
		sa,
		sb,
		ss,
		pa,
		pb,
		ra,
		rb,
		rr,
		rra,
		rrb,
		rrr
    };
void        print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

int             isNumber(char *arg)
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
    t_node *temp;

    temp = stck->top;

    while (temp)
    {
        if (num == temp->content)
            return (0);
        temp = temp->next;
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

void        do_command(t_pushstack *stck, char *cmd)
{
    if (!ft_strcmp(cmd, "sa\n"))
        g_func[0](stck);
    else if (!ft_strcmp(cmd, "sb\n"))
        g_func[1](stck);
    else if (!ft_strcmp(cmd, "ss\n"))
        g_func[2](stck);
    else if (!ft_strcmp(cmd, "pa\n"))
        g_func[3](stck);
    else if (!ft_strcmp(cmd, "pb\n"))
        g_func[4](stck);
    else if (!ft_strcmp(cmd, "ra\n"))
        g_func[5](stck);
    else if (!ft_strcmp(cmd, "rb\n"))
        g_func[6](stck);
    else if (!ft_strcmp(cmd, "rr\n"))
        g_func[7](stck);
    else if (!ft_strcmp(cmd, "rra\n"))
        g_func[8](stck);
    else if (!ft_strcmp(cmd, "rrb\n"))
        g_func[9](stck);
    else if (!ft_strcmp(cmd, "rrr\n"))
        g_func[10](stck);
    else
        print_error();
}

int         main(int ac, char **av)
{
    t_pushstack *stacks;
    t_stack     *stack_a;
    t_stack     *stack_b;
    char    command[5];

    int i = 0;
    stack_b = init();
    stack_a = push_args(ac, av);
    stacks = push_init(stack_a, stack_b);
    ft_bzero((void *)command, 4);
    while (read(0, command, 4))
    {
        printf("command = |%s|\n", command);
        do_command(stacks, command);
        ft_bzero((void *)command, 4);
    }
    return (0);
}