#ifndef PSTYPES_H
# define PSTYPES_H
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

typedef struct s_bounds
{
	int		lower;
	int		upper;
	size_t	size;
	size_t	nb;
}	t_bounds;

typedef struct s_pushswap
{
	t_cmd		*cmdlist;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_array		cmdset;
	t_gc		gc;
	int			*slst;
}	t_pushswap;

#endif
