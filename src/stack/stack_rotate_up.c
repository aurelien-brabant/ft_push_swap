/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:51:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 03:01:43 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

void	stack_rotate_up(t_psstack *stack)
{
	long long	rotated;
	size_t		i;

	rotated = stack_peek(stack);
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		--i;
	}
	stack->data[i] = rotated;
}
