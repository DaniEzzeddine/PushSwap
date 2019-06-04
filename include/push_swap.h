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
}               t_stack;



//Stack
t_stack			*init(void);
int 			isEmpty(t_stack *stack);
int				peek(t_stack *stack);
void			pop(t_stack	*stack);
t_node			*new_node(int	content);
void			push(t_stack *stack, int content);


#endif