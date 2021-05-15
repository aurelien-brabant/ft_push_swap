/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:07:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:22:43 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"

void	stack_rotate_down(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top->next = stack->bot;
	stack->top->next->prev = stack->top;
	stack->top = stack->top->next;
	stack->bot = stack->bot->next;
	stack->bot->prev = NULL;
	stack->top->next = NULL;
}
