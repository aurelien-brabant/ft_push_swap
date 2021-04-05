/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:51:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:22:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

void	stack_rotate_up(t_psstack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top->next = stack->bot;
	stack->top->next->prev = stack->top;
	stack->bot = stack->top;
	stack->top = stack->bot->prev;
	stack->top->next = NULL;
	stack->bot->prev = NULL;
}
