/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:42:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 19:47:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"
#include "cmd.h"

void	cmd_rotate_up_double(t_pshswp_stack *a, t_pshswp_stack *b)
{
	cmd_rotate_up_a(a, b);
	cmd_rotate_up_b(a, b);
}

void	cmd_rotate_down_double(t_pshswp_stack *a, t_pshswp_stack *b)
{
	cmd_rotate_down_a(a, b);
	cmd_rotate_down_b(a, b);
}
