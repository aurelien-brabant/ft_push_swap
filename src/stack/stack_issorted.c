/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:44:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/10 23:46:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

bool	stack_issorted(t_psstack *stack)
{
	t_psnode	*cur;

	if (stack->top == NULL)
		return (true);
	cur = stack->top;
	while (cur->prev != NULL)
	{
		if (cur->val > cur->prev->val)
			return  (false);
		cur = cur->prev;
	}
	return (true);
}
