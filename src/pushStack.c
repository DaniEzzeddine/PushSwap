#include "../include/push_swap.h"

t_pushstack 	*push_init(t_stack *a, t_stack *b)
{
	t_pushstack *fresh;

	fresh = ft_memalloc(sizeof(t_pushstack));
	fresh->a = a;
	fresh->b = b;
	return (fresh);
}

void 				push_delete(t_pushstack **stack)
{
	freeStack(&(*stack)->a);
	(*stack)->a = NULL;
	freeStack(&(*stack)->b);
	(*stack)->b = NULL;
	free(*stack);
	stack = NULL;
}

void 				sa(t_pushstack *stack)
{
	// printf("here\n");
	if(!isEmpty(stack->a) || stack->a->size == 1)
		swap(stack->a);
	// printf("here\n");
}

void 				sb(t_pushstack *stack)
{
	if(!isEmpty(stack->b) || stack->b->size == 1)
		swap(stack->b);
}

void 				ss(t_pushstack *stack)
{
	sa(stack);
	sb(stack);
}

void 			ra(t_pushstack *stack)
{
	if (!isEmpty(stack->a))
		rotateUp(stack->a);
}

void 			rb(t_pushstack *stack)
{
	if (!isEmpty(stack->b))
		rotateUp(stack->b);
}

void 		rr(t_pushstack *stack)
{
	if (!isEmpty(stack->a))
		rotateUp(stack->a);
	if (!isEmpty(stack->b))
		rotateUp(stack->b);
}

void 		rra(t_pushstack *stack)
{
	if (!isEmpty(stack->a))
		rotateDown(stack->a);
}

void 		rrb(t_pushstack *stack)
{
	if (!isEmpty(stack->b))
		rotateDown(stack->b);
}

void 		rrr(t_pushstack *stack)
{
	if (!isEmpty(stack->a))
		rotateDown(stack->a);
	if (!isEmpty(stack->b))
		rotateDown(stack->b);
}

void 	pa(t_pushstack *stack)
{
	int 	topB;
	if (!isEmpty(stack->b))
	{
		topB = peek(stack->b);
		pop(stack->b);
		push(stack->a, topB);
	}
}

void 	pb(t_pushstack *stack)
{
	int 	topA;
	if (!isEmpty(stack->a))
	{
		topA = peek(stack->a);
		pop(stack->a);
		push(stack->b, topA);
	}
}