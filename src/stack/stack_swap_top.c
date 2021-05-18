/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 06:15:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 14:26:02 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"

void	stack_swap_top(t_stack *stack)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top->val;
	stack->top->val = stack->top->prev->val;
	stack->top->prev->val = tmp;
}
