#include "../include/push_swap.h"

t_stack	*init(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->top = NULL;
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

void			pop(t_stack	*stack)
{
	if (isEmpty(stack))
		return ;
	stack->top = stack->top->next;
	
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
}

