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

void	split(t_pushswap *ps, t_stack *stack, int median)
{
	int			i;

	i = ps->stack_a->size;
	while (i > 0)
	{
		if (stack_peek(stack) < median)
			outcmd(ps, PS_PUSH_B);
		else
			outcmd(ps, PS_ROT_A);
		--i;
	}
}

/*
static void	sort_a_on_b(t_pushswap *ps, int median)
{
	int	min_index;

	while (ps->stack_a->size > 0)
	{
		stack_get_min(ps->stack_a, NULL, &min_index);
		move_to_top(ps, ps->stack_a, min_index);
		outcmd(ps, PS_PUSH_B);
	}
		outcmd(ps, PS_SWAP_A);
	while (stack_peek(ps->stack_b) > median)
		outcmd(ps, PS_PUSH_A);
}

void	sort_b(t_pushswap *ps)
{
	int	min_ind;
	int	max_ind;
	int	item_ind;
	int	mid_size;

	while (ps->stack_b->size > 0)
	{
		mid_size = ps->stack_a->size / 2;
		stack_get_max(ps->stack_b, NULL, &max_ind);
		move_to_top(ps, ps->stack_b, max_ind);
		outcmd(ps, PS_PUSH_A);
	}
}
*/

void	sort100(t_pushswap *ps)
{
	int	median;

	median = get_median(ps->slst, ps->stack_a->size);
	split(ps, ps->stack_a, median);	
	//sort_b(ps);
	print_stack(ps->stack_b);
}
