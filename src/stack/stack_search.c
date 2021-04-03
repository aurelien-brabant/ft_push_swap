/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:09:27 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 13:24:22 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

int	stack_search(t_psstack *stack, int nb)
{
	size_t	i;
	size_t	size;

	size = stack_size(stack);
	i = 0;
	while (i < size)
	{
		if (stack->data[i] == nb)
			return (i);
		++i;
	}
	return (-1);
}
