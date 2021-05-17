/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:26:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/17 09:40:22 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/array.h"
#include "pushswap/stack.h"

int	*stack_to_array(t_stack *stack)
{
	int			*a;
	t_psnode	*cur;
	size_t		i;

	a = malloc(stack->size * sizeof(int));
	if (a == NULL)
		return (a);
	cur = stack->top;
	i = 0;
	while (cur != NULL)
	{
		a[i++] = cur->val;
		cur = cur->prev;
	}
	return (a);
}
