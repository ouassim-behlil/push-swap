#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stdlib.h"
# include "unistd.h"
# include <limits.h>

typedef	struct s_node
{
	struct s_node		*prev;
	struct s_node		*next;
	int 				value;
	int					index;
} t_node;

typedef struct s_stack
{
	struct s_node		*top;
	struct s_node		*bottom;
	int 				size;
} t_stack;

int			is_digit(int c);
bool		is_white_space(int c);
int			ft_atoi(const char *str, int *error);

void		push(t_stack *stack, t_node *node);
t_node		*pop(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
t_node		*peek(t_stack *stack);

bool		is_empty(t_stack *stack);
void		swap(t_stack *a);
void		push_from(t_stack *from, t_stack *to);
t_node		*create_node(int val);
t_stack		*create_empty_stack(void);
int			*stack_to_array(t_stack *stack);

size_t   	ft_countwords(const char *str, char c);
char    	**ft_split(char const *s, char c);
void 		free_split(char **split);
void 		free_stack(t_stack *stack);

t_stack 	*create_fill_stack(int argc, char **argv);
bool		stack_indexing(t_stack *stack);

int			index_of_lowest_cost(t_stack *from, t_stack *to);
int			min_rotations_to_top(t_stack *from, int index);
int			insertion_cost(t_stack *to, int index);
void		push_all_chunks(t_stack *from, t_stack *to);
int			find_lower_bound(t_stack *stack, int index);
int			min_index(t_stack *stack);
int			max_index(t_stack *stack);
void		push_swap(t_stack *stack);

#endif
