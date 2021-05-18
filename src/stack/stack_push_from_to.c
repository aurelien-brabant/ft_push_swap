/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_from_to.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:28:24 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 14:28:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "pushswap/stack.h"

static void	handle_empty_dest_stack(t_stack *from, t_stack *to,
		t_psnode *new_from_top)
{
	to->top = from->top;
	to->bot = from->top;
	to->top->prev = NULL;
	to->top->next = NULL;
	from->top = new_from_top;
}

void	stack_push_from_to(t_stack *from, t_stack *to)
{
	t_psnode	*new_from_top;

	if (from->size == 0)
		return ;
	new_from_top = from->top->prev;
	if (to->size == 0)
		handle_empty_dest_stack(from, to, new_from_top);
	else
	{
		to->top->next = from->top;
		to->top->next->next = NULL;
		to->top->next->prev = to->top;
		to->top = to->top->next;
		from->top = new_from_top;
		if (from->top != NULL)
			from->top->next = NULL;
		else
			from->bot = NULL;
	}
	++to->size;
	--from->size;
}
