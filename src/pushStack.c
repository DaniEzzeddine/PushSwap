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
	swap(stack->a);
}

void 				sb(t_pushstack *stack)
{
	swap(stack->b);
}

void 				ss(t_pushstack *stack)
{
	swap(stack->a);
	swap(stack->b);
}

void 			ra(t_pushstack *stack)
{
	rotateUp(stack->a);
}

void 			rb(t_pushstack *stack)
{
	rotateUp(stack->b);
}

void 		rr(t_pushstack *stack)
{
	rotateUp(stack->a);
	rotateUp(stack->b);
}

void 		rra(t_pushstack *stack)
{
	rotateDown(stack->a);
}

void 		rrb(t_pushstack *stack)
{
	rotateDown(stack->b);
}

void 		rrr(t_pushstack *stack)
{
	rotateDown(stack->a);
	rotateDown(stack->b);
}

void 	pa(t_pushstack *stack)
{
	int 	topA;

	topA = peek(stack->a);
	pop(stack->a);
	push(stack->b, topA);
}

void 	pb(t_pushstack *stack)
{
	int 	topB;

	topB = peek(stack->b);
	pop(stack->b);
	push(stack->a, topB);
}