/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lookup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:09:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 04:34:43 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

/*
** NOTE: if index is found to be greater than half of the stack's size,
** then let's start from the top, otherwise from the bottom. Thanks to that
** little trick, it should go faster unless the searched element is always
** at the middle of the stack.
*/

int	stack_lookup(t_psstack *stack, size_t index)
{
	t_psnode	*cur;
	size_t		i;

	if (index < stack->size / 2)
	{
		i = 0;
		cur = stack->bot;
		while (i++ < index)
			cur = cur->next;
	}
	else
	{
		 i = stack->size - 1;
		 cur = stack->top;
		 while (i-- > index)
			 cur = cur->prev;
	}
	return (cur->val);
}
