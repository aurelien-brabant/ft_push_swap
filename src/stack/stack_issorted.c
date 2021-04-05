/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:44:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 04:50:20 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

bool	stack_issorted(t_psstack *stack)
{
	t_psnode	*cur;

	cur = stack->top;
	while (cur->prev != NULL)
	{
		if (cur->val > cur->prev->val)
			return  (false);
		cur = cur->prev;
	}
	return (true);
}
