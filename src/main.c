#include "../include/push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack, char name)
{
	t_node 		*iter;
	printf("*** Stack %c ***\n", name);
	printf("\t\t max = %d min = %d\n", stack->max, stack->min);

	if (isEmpty(stack)) {
		printf("\n(null)\n");
		return ;
	}
	iter = stack->top;
	while(iter->next) {
		printf(" %d ", iter->content);
		iter = iter->next;
	}
	printf(" %d\n", iter->content);
}

void print_stacks(t_pushstack *stacks)
{
	print_stack(stacks->a, 'A');
	print_stack(stacks->b, 'B');
}


int main(int argc, char **argv)
{
	t_pushstack 	*stacks;

	stacks = push_init(init(), init());
	fill(stacks->a, argv+1, argc-1);
	print_stacks(stacks);
	while (!isSorted(stacks->a))
	{
		solve_push_swap(stacks);
		print_stacks(stacks);
	}
	push_delete(&stacks);
	return (0);
}