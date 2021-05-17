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

/*
** Push all integers in stack A that are below the median into stack B.
*/

void	split(t_pushswap *ps, t_stack *stack, int lb, int ub)
{
	int			i;
	int			lim;

	lim = ps->stack_a->size / 2 + 1;
	//if (stack->size % 2 != 0)
		//lim = stack->size / 2 + 1;
	i = ps->stack_a->size;
	while ((int)ps->stack_b->size < lim && i > 0)
	{
		if (stack_peek(stack) >= lb && stack_peek(stack) <= ub)
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

static void	move_item_to_top(t_pushswap *ps, int item_index, int lb, int ub)
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
		/*
		if (!rflag && peak_a >= lb && peak_a <= ub 
			&& peak_a < item_val)
		{
			cmd = PS_ROT_AB;
			rflag = true;	
		}
		else
		*/
		cmd = PS_ROT_B;
	}
	while (offset-- > 0)
		outcmd(ps, cmd);
}

static void insert(t_pushswap *ps, int lb, int ub)
{
	int	peek_a;

	peek_a = stack_peek(ps->stack_a);
	//consider that only if top element on A was part of the B stack.
	if (peek_a >= lb && peek_a <= ub && peek_a < stack_peek(ps->stack_b))
		outcmd(ps, PS_ROT_A);
	outcmd(ps, PS_PUSH_A);
}

static void	insert_all(t_pushswap *ps, int lb, int ub)
{
	int	selected_index;

	while (!stack_isempty(ps->stack_b))
	{
		selected_index = select_value_by_index(ps->stack_b);
		/* move selected min/max to the top of the stack B */
		move_item_to_top(ps, selected_index, lb, ub);
		/* the insert it at the right place in stack A */
		insert(ps, lb, ub);
	}
	while (stack_peek(ps->stack_a) >= lb && stack_peek(ps->stack_a) <= ub)
		outcmd(ps, PS_ROT_A);
}

void	sort100(t_pushswap *ps)
{
	int	median;

	median = get_median(ps->slst, ps->stack_a->size);
	split(ps, ps->stack_a, ps->stack_a->min, median - 1);
	insert_all(ps, ps->stack_a->min, median - 1);
	split(ps, ps->stack_a, median, ps->stack_a->max);
	insert_all(ps, median, ps->stack_a->max);
}
