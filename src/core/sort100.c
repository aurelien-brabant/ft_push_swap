/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:16:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/17 14:38:45 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft/cstring.h"

#include "pushswap/debug.h"
#include "pushswap/core.h"
#include "pushswap/stack.h"
#include "pushswap/cmd.h"

/*
** Prototype optimized to work with exacty 100 values. Extrapolation will
** be done for other cases when this one will be finished and working as
** expected.
*/

static int	get_median(int *a, size_t size)
{
	int	mid;

	mid = size / 2;
	if (size % 2 == 0)
		return ((a[mid] + a[mid + 1]) / 2);
	return(a[mid]);
}

static bool	is_oob(int v, t_bounds bounds)
{
	return (!(v >= bounds.lower && v <= bounds.upper));
}

/*
** Push all integers in stack A that are below the median into stack B.
** Do not push more than stack_size / 2 + 1 on stack B to save some ra.
*/

void	split(t_pushswap *ps, t_bounds bounds)
{
	int			i;
	int			lim;

	lim = ps->stack_a->size / 2 + 1;
	i = ps->stack_a->size;
	while ((int)ps->stack_b->size < lim && i > 0)
	{
		if (!is_oob(stack_peek(ps->stack_a), bounds))
			outcmd(ps, PS_PUSH_B);
		else
			outcmd(ps, PS_ROT_A);
		--i;
	}
}
static int	select_value_by_index(t_stack *stack)
{
	int	min_ind;
	int	max_ind;
	int	min_offset;
	int	max_offset;

	stack_get_min(stack, NULL, &min_ind);
	stack_get_max(stack, NULL, &max_ind);
	if (min_ind > (int)stack->size / 2)
		min_offset = stack->size - min_ind;
	else
		min_offset = min_ind;
	if (max_ind > (int)stack->size / 2)
		max_offset = stack->size - max_ind;
	else
		max_offset = max_ind;
	if (max_offset <= min_offset)
		return (max_ind);
	return (min_ind);
}

static const char	*optimize(t_pushswap *ps, const char *cmd, t_bounds bounds, int item_index)
{
	int	item_val;
	int	peek_a;

	item_val = gsv(ps->stack_b, item_index);
	peek_a = stack_peek(ps->stack_a);
	if (ft_strcmp(cmd, PS_ROT_B) == 0 && !is_oob(peek_a, bounds) && peek_a < item_val)
		return (PS_ROT_AB);
	return (cmd);
}

static void	move_item_to_top(t_pushswap *ps, int item_index, t_bounds bounds)
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
		outcmd(ps, optimize(ps, cmd, bounds, item_index));
}

static void insert(t_pushswap *ps, t_bounds bounds)
{
	int	peek_a;

	peek_a = stack_peek(ps->stack_a);
	if (!is_oob(peek_a, bounds) && peek_a < stack_peek(ps->stack_b))
		outcmd(ps, PS_ROT_A);
	outcmd(ps, PS_PUSH_A);
}

static void	insert_all(t_pushswap *ps, t_bounds bounds)
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

/*
** Optimized sorting for 100 items.
** CURRRENT_STATE: in most cases sorting is done with < 900 instructions.
** Works for any number of items, but is not super efficient.
*/

void	sort100(t_pushswap *ps)
{
	int	median;

	median = get_median(ps->slst, ps->stack_a->size);
	split(ps, (t_bounds){ps->stack_a->min, median - 1});
	insert_all(ps, (t_bounds){ps->stack_a->min, median - 1});
	split(ps, (t_bounds){median, ps->stack_a->max});
	insert_all(ps, (t_bounds){median, ps->stack_a->max});
}
