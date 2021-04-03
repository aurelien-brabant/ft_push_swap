/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:02:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 01:52:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

void	cmd_rotate_up_a(t_psstack *a, t_psstack *b)
{
	(void)b;
	if (stack_size(a) > 0)
		stack_rotate_up(a);
}

void	cmd_rotate_up_b(t_psstack *a, t_psstack *b)
{
	(void)a;
	if (stack_size(b) > 0)
		stack_rotate_up(b);
}

void	cmd_rotate_down_a(t_psstack *a, t_psstack *b)
{
	(void)b;
	if (stack_size(a) > 0)
		stack_rotate_down(a);
}

void	cmd_rotate_down_b(t_psstack *a, t_psstack *b)
{
	(void)a;
	if (stack_size(b) > 0)
		stack_rotate_down(b);
}
