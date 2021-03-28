/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:05:17 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 23:10:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pshswp_stack.h"

t_pshswp_stack	*stack_new(void)
{
	t_pshswp_stack	*stack;

	stack = malloc(sizeof (*stack));
	if (stack == NULL)
		return (NULL);
	stack->size = 0;
	stack->capacity = 10;
	stack->data = malloc(sizeof (long long) * stack->capacity);
	if (stack->data == NULL)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
