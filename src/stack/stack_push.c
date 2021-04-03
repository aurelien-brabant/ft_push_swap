/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:12:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 12:07:48 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/cstring.h"
#include "psstack.h"

static void	resize(t_psstack *stack)
{
	int	*new_data;

	new_data = malloc(sizeof (int) * stack->capacity * 2);
	if (new_data != NULL)
	{
		stack->capacity *= 2;
		ft_memcpy(new_data, stack->data, sizeof (int) * stack->size);
		free(stack->data);
		stack->data = new_data;
	}
}

void	stack_push(t_psstack *stack, int nb)
{
	if (stack->size == stack->capacity)
		resize(stack);
	stack->data[stack->size++] = nb;
}
