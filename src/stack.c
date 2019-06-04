#include "../include/push_swap.h"
commands *g_func[4] = {
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

t_stack	*init(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->top = NULL;
	stack->max = INT32_MAX;
	stack->min = INT32_MIN;
	return (stack);
}

int 			isEmpty(t_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

int				peek(t_stack *stack)
{
	return (stack->top->content);
}



int 			stackMax(t_stack *stack)
{
	return stack->max;
}

int 			stackMin(t_stack *stack)
{
	return stack->min;
}

t_node		*new_node(int	content)
{
	t_node		*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
	
void			pop(t_stack	*stack)
{
	int 	oldTop;

	if (isEmpty(stack))
		return ;
	
	oldTop = peek(stack);
	stack->top = stack->top->next;
	if (oldTop == stack->max)
		stack->max = stackMax(stack);
	if (oldTop == stack->min)
		stack->min = stackMin(stack);
}

void	push(t_stack *stack, int content)
{
	t_node *node;

	node = new_node(content);
	if (isEmpty(stack))
		stack->top = node;
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
	if (stack->max < content)
		stack->max = content;
	if (stack->min > content)
		stack->min = content;
}

void 	freeStack(t_stack **stack)
{
	t_node 	*iter;
	t_node *next;

	iter = (*stack)->top;
	while(iter)
	{
		next = iter->next;		
		iter->next = NULL;
		free(iter);
		iter = next;
	}
	free(*stack);
	*stack = NULL;
}