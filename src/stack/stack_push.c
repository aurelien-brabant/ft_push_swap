/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:12:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 16:46:57 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/cstring.h"

#include "pushswap/stack.h"

/*
** This stack_push function is used when parsing is done ONLY. At the end of the day the only function used
** to perform push_swap push/pop operations is stack_push_from_to. Therefore stack_push implements the capability
** of keeping the maximum value as new values are pushed.
*/

void	stack_push(t_stack *stack, int nb)
{
	t_psnode	*new_node;

	new_node = malloc(sizeof (*new_node));
	if (new_node == NULL)
		return ;
	if (nb > stack->max)
		stack->max = nb;
	if (nb < stack->min)
		stack->min = nb;
	new_node->next = NULL;
	new_node->val = nb;
	new_node->prev = stack->top;
	stack->size++;
	if (stack->bot == NULL)
	{
		stack->bot = new_node;
		stack->top = new_node;
		return ;
	}
	stack->top->next = new_node;
	stack->top = new_node;
}
