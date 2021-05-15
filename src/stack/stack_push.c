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

void	stack_push(t_stack *stack, int nb)
{
	t_psnode	*new_node;

	new_node = malloc(sizeof (*new_node));
	if (new_node == NULL)
		return ;
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
