#ifndef PS_TYPES_H
# define PS_TYPES_H
# include "libft/array.h"
# include "libft/gc.h"

typedef struct s_psnode
{
	struct s_psnode		*prev;
	struct s_psnode		*next;
	int					val;
}	t_psnode;

typedef struct s_stack
{
	size_t			size;
	int				max; 
	int				min;
	struct s_psnode	*top;
	struct s_psnode	*bot;
}	t_stack;

typedef struct s_cmd
{
	char	*name;
	void	(*trigger)(t_stack *a, t_stack *b);
}				t_cmd;

/*
** chunk type definition for chunk_sort
*/

typedef struct s_chunk
{
	int	lb; /* lower bound */
	int	ub; /* upper bound */
}	t_chunk;

typedef struct s_bounds
{
	int lower;
	int upper;
}	t_bounds;

typedef struct s_pushswap
{
	t_cmd	*cmdlist;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_array	cmdset;
	t_gc		gc;
	int			*slst;
}	t_pushswap;

#endif
