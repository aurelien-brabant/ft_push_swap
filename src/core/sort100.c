/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:16:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/17 10:32:01 by abrabant         ###   ########.fr       */
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

static int scan_from_top_for_less_than(t_stack *target, int lim)
{
	t_psnode	*cur;
	int			index;

	index = 0;
	cur = target->top;
	while (cur != NULL)
	{
		if (cur->val < lim)
			return (index);
		cur = cur->prev;
		++index;
	}
	return (-1);
}

static int scan_from_bot_for_less_than(t_stack *target, int lim)
{
	t_psnode	*cur;
	int			index;

	index = target->size - 1;
	cur = target->bot;
	while (cur != NULL)
	{
		if (cur->val < lim)
			return (index);
		cur = cur->next;
		--index;
	}
	return (-1);
}

void	move_to_top(t_pushswap *ps, t_stack *target, int item_index)
{
	const char	*cmd;
	int			offset;

	if (item_index > target->size / 2)
	{
		offset = target->size - item_index;
		if (target == ps->stack_a)
			cmd = PS_REV_ROT_A;
		else
			cmd = PS_REV_ROT_B;
	}
	else
	{
		offset = item_index;
		if (target == ps->stack_a)
			cmd = PS_ROT_A;
		else
			cmd = PS_ROT_B;
	}
	while (offset-- > 0)
		outcmd(ps, cmd);
}

void	sort100(t_pushswap *ps)
{
	int	median; 
	int	bot_ind;
	int	top_ind;
	int	item_ind;

	median = get_median(ps->slst, ps->stack_a->size);
	printf("\nmedian is: %d\n", median);
	while (1)
	{
		top_ind = scan_from_top_for_less_than(ps->stack_a, median);
		bot_ind = scan_from_bot_for_less_than(ps->stack_a, median);
		if (top_ind == -1 && bot_ind == -1)
			break ;
		if (top_ind < (int)ps->stack_a->size - bot_ind)
			item_ind = top_ind;
		else
			item_ind = bot_ind;
		move_to_top(ps, ps->stack_a, item_ind);
		outcmd(ps, PS_PUSH_B);
	}
	print_stack(ps->stack_b);
}
