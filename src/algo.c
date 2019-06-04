#include "../include/push_swap.h"

int			isSorted(t_stack *a)
{
	t_node	*iter;

	iter = a->top;
	while (iter->next)
	{
		if (iter->content > iter->next->content)
			return (0);
		iter = iter->next;
	}
	return (1);
}

int			getPos(t_stack *a, int mn)
{
	t_node 	*iter;
	int		i;

	iter = a->top;
	i = 0;
	while(iter)
	{
		if (mn == iter->content)
			return (i);
		iter = iter->next;
		i++;
	}
	return (-1);
}

void	sort_3(t_pushstack *stacks)
{
	int pos;

	if (stacks->a->size == 1)
		return ;
	if (stacks->a->size == 3)
	{
		pos = getPos(stacks->a, stacks->a->max);
		if (!pos)
		{
			//print_ops("ra\n");
			ra(stacks);
		}
		if (pos == 1)
		{
			// print_ops("rra\n");
			rra(stacks);
		}
	}
	if (stacks->a->top->content > stacks->a->top->next->content)
	{
		// print_ops("sa\n");
		sa(stacks);
	}
}

void		transfer_to_a(t_pushstack *stacks)
{
	while (!isEmpty(stacks->b))
		pa(stacks);
}

void        solve_push_swap(t_pushstack *stacks)
{
	int pos;

	while (stacks->a->size > 3)
	{
		pos = getPos(stacks->a, stacks->a->min);
		if (pos == 0)
			pb(stacks);
		else if (pos >= (stacks->a->size) / 2)
			ra(stacks);
		else
			rra(stacks);
	}
	sort_3(stacks);
	transfer_to_a(stacks);
}