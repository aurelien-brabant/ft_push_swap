/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 15:08:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"

void	cmd_push_a(t_pshswp_stack *a, t_pshswp_stack *b)
{
	stack_push(a, stack_pop(b));
}

void	cmd_push_b(t_pshswp_stack *a, t_pshswp_stack *b)
{
	stack_push(b, stack_pop(a));
}

void	cmd_swap_a(t_pshswp_stack *a)
{
	long long	top;
	long long	top_minus_one;

	top = stack_pop(a);
	top_minus_one = stack_pop(a);
	stack_push(a, top);
	stack_push(a, top_minus_one);
}

void	cmd_swap_b(t_pshswp_stack *b)
{
	long long	top;
	long long	top_minus_one;

	top = stack_pop(b);
	top_minus_one = stack_pop(b);
	stack_push(b, top);
	stack_push(b, top_minus_one);
}

void	cmd_swap_double(t_pshswp_stack *a, t_pshswp_stack *b)
{
	cmd_swap_a(a);
	cmd_swap_b(b);
}
