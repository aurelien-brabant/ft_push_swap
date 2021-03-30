/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:44:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 13:54:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"

bool	stack_issorted(t_pshswp_stack *stack)
{
	size_t	top;

	top = stack_size(stack) - 1;
	while (top > 0)
	{
		if (stack->data[top] > stack->data[top - 1])
			return (false);
		--top;
	}
	return (true);
}
