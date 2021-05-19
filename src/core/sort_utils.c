#include "libft/cstring.h"

#include "pushswap/pscore.h"
#include "pushswap/stack.h"
#include "pushswap/cmd.h"

/*
** Split a part of stack A, put it in stack B.
** Elements included in bounds are pushed on stack B.
** The goal is to split the stack A multiple times, starting with the
** smallest values to the greatest ones. The entire stack may be rotated
** even if all the elements have been pushed, to ensure elements in stack A
** are still ordered properly.
*/

void	split(t_pushswap *ps, t_bounds bounds)
{
	int			i;
	int			selected_b;

	if (bounds.size == 0)
	{
		while (!is_oob(stack_peek(ps->stack_a), bounds))
			outcmd(ps, PS_PUSH_B);
		return ;
	}
	i = ps->stack_a->size;
	while (i > 0)
	{
		if (bounds.nb < 1 && ps->stack_b->size >= bounds.size)
			break ;
		selected_b = select_value_by_index(ps->stack_b);
		if (!is_oob(stack_peek(ps->stack_a), bounds))
			outcmd(ps, PS_PUSH_B);
		else if (selected_b != 0 && selected_b < (int)ps->stack_b->size / 2)
			outcmd(ps, PS_ROT_AB);
		else
			outcmd(ps, PS_ROT_A);
		--i;
	}
}

/*
** Check if some optimization can be done to use rr instead of rb when
** rotating the selected value to the top of stack B.
*/

static const char	*optimize_for_rr(t_pushswap *ps, const char *cmd,
						t_bounds bounds, int item_index)
{
	int	item_val;
	int	peek_a;

	item_val = gsv(ps->stack_b, item_index);
	peek_a = stack_peek(ps->stack_a);
	if (ft_strcmp(cmd, PS_ROT_B) == 0
		&& !is_oob(peek_a, bounds) && peek_a < item_val)
		return (PS_ROT_AB);
	return (cmd);
}

/*
** Move the selected item to the top of stack B.
*/

void	move_item_to_top(t_pushswap *ps, int item_index, t_bounds bounds)
{
	const char	*cmd;
	int			offset;

	if (item_index == 0)
		return ;
	if (item_index > ps->stack_b->size / 2.0)
	{
		offset = ps->stack_b->size - item_index;
		cmd = PS_REV_ROT_B;
	}
	else
	{
		offset = item_index;
		cmd = PS_ROT_B;
	}
	while (offset-- > 0)
		outcmd(ps, optimize_for_rr(ps, cmd, bounds, item_index));
}

/*
** Insert value on top of stack B at the correct position in stack A.
*/

static void	insert(t_pushswap *ps, t_bounds bounds)
{
	int	peek_a;

	peek_a = stack_peek(ps->stack_a);
	if (!is_oob(peek_a, bounds) && peek_a < stack_peek(ps->stack_b))
		outcmd(ps, PS_ROT_A);
	outcmd(ps, PS_PUSH_A);
}

/*
** Insert all the values in stack B in the correct position in stack A.
*/

void	insert_all(t_pushswap *ps, t_bounds bounds)
{
	int	selected_index;

	while (!stack_isempty(ps->stack_b))
	{
		selected_index = select_value_by_index(ps->stack_b);
		move_item_to_top(ps, selected_index, bounds);
		insert(ps, bounds);
	}
	while (!is_oob(stack_peek(ps->stack_a), bounds))
		outcmd(ps, PS_ROT_A);
}
