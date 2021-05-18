/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lookup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:09:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 23:17:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"

/*
** Get the integer value available at position index.
** NOTE: index 0 points to the top of the stack, therefore index stack_size - 1
** points to the bottom of it.
*/

int	stack_lookup(t_stack *stack, size_t index)
{
	t_psnode	*cur;
	size_t		i;

	if (index > stack->size / 2)
	{
		i = stack->size - 1;
		cur = stack->bot;
		while (i-- > index)
			cur = cur->next;
	}
	else
	{
		 i = 0;
		 cur = stack->top;
		 while (i++ < index)
			 cur = cur->prev;
	}
	return (cur->val);
}
