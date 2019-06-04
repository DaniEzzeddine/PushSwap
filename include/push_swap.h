#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

typedef struct s_node {
	   int          content;
	   struct s_node *next;
}               t_node;

typedef struct s_stack {
	   struct s_node *top;
	   int 		max;
	   int 		min;
}               t_stack;

typedef struct s_pushstack {
	struct s_stack *a;
	struct s_stack *b;
}				t_pushstack;	






t_stack		*init(void);
int 			isEmpty(t_stack *stack);
int				peek(t_stack *stack);
void			pop(t_stack	*stack);
t_node		*new_node(int	content);
void			push(t_stack *stack, int content);
int 			findMax(t_stack *a);
int 			findMin(t_stack *a);
int 			stackMax(t_stack *a);
int 			stackMin(t_stack *a);
void 			rotateDown(t_stack *a);
void			rotateUp(t_stack *a);
void			swap(t_stack *a);
void 			freeStack(t_stack **stack);


t_pushstack			*push_init(t_stack *a, t_stack *b);
void					push_delete(t_pushstack **stack);

void 	pb(t_pushstack *stack);
void 	pa(t_pushstack *stack);

void 		rrr(t_pushstack *stack);
void 		rrb(t_pushstack *stack);
void 		rra(t_pushstack *stack);

void 		rr(t_pushstack *stack);
void 		ra(t_pushstack *stack);
void 		rb(t_pushstack *stack);

void 		ss(t_pushstack *stack);
void 		sa(t_pushstack *stack);
void 		sb(t_pushstack *stack);

typedef void commands(t_pushstack	*stack);


#endif