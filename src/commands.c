#include "../include/push_swap.h"

void 	swap(t_stack *a)
{
	t_node 	*second;
	second = a->top->next;
	a->top->next = second->next;
	second->next = a->top;
	a->top = second;
}

void rotateUp(t_stack *a)
{
	t_node 		*iter;
	int 			topValue;

	topValue = peek(a);
	pop(a);	
	iter = a->top;	
	while(iter->next)
		iter = iter->next;
	iter->next = new_node(topValue);
}

void rotateDown(t_stack *a)
{
	t_node 	*iter;
	t_node 	*freshTop;
	int 		bottomValue;

	iter = a->top;
	if (!iter || !iter->next)
		return ;
	while(iter->next->next)
		iter = iter->next;
	bottomValue = (iter->next->content);
	free(iter->next);
	iter->next = NULL;
	freshTop = new_node(bottomValue);
	freshTop->next = a->top;
	a->top = freshTop;	
}


int 	findMax(t_stack *a)
{
	t_node 	*iter;
	int 		max;

	iter = a->top;
	max = INT32_MIN;
	while (iter)
	{
		if (iter->content > max)
			max = iter->content;
		iter = iter->next;
	}
	return max;
}

int findMin(t_stack *a)
{
	t_node 	*iter;
	int 		min;

	iter = a->top;
	min = INT32_MAX;
	while(iter)
	{
		if (min > iter->content)
			min = iter->content;
		iter = iter->next;
	}
	return (min);
}