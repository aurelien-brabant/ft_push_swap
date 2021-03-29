/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 19:46:04 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"
#include <stdio.h>

void	cmd_push_a(t_pshswp_stack *a, t_pshswp_stack *b)
{
	if (stack_size(b) > 0)
		stack_push(a, stack_pop(b));
}

void	cmd_push_b(t_pshswp_stack *a, t_pshswp_stack *b)
{
	if (stack_size(a) > 0)
		stack_push(b, stack_pop(a));
}

void	cmd_swap_a(t_pshswp_stack *a, t_pshswp_stack *b)
{
	long long	top;
	long long	top_minus_one;
	
	(void)b;
	if (stack_size(a) < 2)
		return ;
	top = stack_pop(a);
	top_minus_one = stack_pop(a);
	stack_push(a, top);
	stack_push(a, top_minus_one);
}

void	cmd_swap_b(t_pshswp_stack *a, t_pshswp_stack *b)
{
	long long	top;
	long long	top_minus_one;

	(void)a;
	if (stack_size(b) < 2)
		return ;
	top = stack_pop(b);
	top_minus_one = stack_pop(b);
	stack_push(b, top);
	stack_push(b, top_minus_one);
}

void	cmd_swap_double(t_pshswp_stack *a, t_pshswp_stack *b)
{
	cmd_swap_a(a, b);
	cmd_swap_b(a, b);
}
