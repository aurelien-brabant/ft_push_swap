/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:02:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 19:46:23 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"

void	cmd_rotate_up_a(t_pshswp_stack *a, t_pshswp_stack *b)
{
	(void)b;
	stack_rotate_up(a);
}

void	cmd_rotate_up_b(t_pshswp_stack *a, t_pshswp_stack *b)
{
	(void)a;
	stack_rotate_up(b);
}

void	cmd_rotate_down_a(t_pshswp_stack *a, t_pshswp_stack *b)
{
	(void)b;
	stack_rotate_down(a);
}

void	cmd_rotate_down_b(t_pshswp_stack *a, t_pshswp_stack *b)
{
	(void)a;
	stack_rotate_down(b);
}
