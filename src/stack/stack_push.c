/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:12:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 23:38:32 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/cstring.h"
#include "pshswp_stack.h"

static void	resize(t_pshswp_stack *stack)
{
	long long	*new_data;

	new_data = malloc(sizeof (long long) * stack->capacity * 2);
	if (new_data != NULL)
	{
		stack->capacity *= 2;
		ft_memcpy(new_data, stack->data, sizeof (long long) * stack->size);
		free(stack->data);
		stack->data = new_data;
	}
}

void	stack_push(t_pshswp_stack *stack, long long nb)
{
	if (stack->size == stack->capacity)
		resize(stack);
	stack->data[stack->size++] = nb;
}
