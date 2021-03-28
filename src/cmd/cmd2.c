/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:02:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 15:08:48 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"

void	cmd_rotate_up_double(t_pshswp_stack *a, t_pshswp_stack *b)
{
	stack_rotate_up(a);
	stack_rotate_up(b);
}

void	cmd_rotate_down_double(t_pshswp_stack *a, t_pshswp_stack *b)
{
	stack_rotate_down(a);
	stack_rotate_down(b);
}
