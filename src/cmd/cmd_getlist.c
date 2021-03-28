/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:44:33 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 14:13:25 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "pshswp_stack.h"

t_cmd	*cmdlist_get(void)
{
	static t_cmd	list[CMD_NB] = {{"sa", cmd_swap_a}, {"sb", cmd_swap_b},
		{"ss", cmd_swap_double}, {"pa", cmd_push_a}, {"pb", cmd_push_b},
		{"ra", stack_rotate_up}, {"rb", stack_rotate_up},
		{"rr", cmd_rotate_up_double}, {"rra", stack_rotate_down},
		{"rrb", stack_rotate_down}, {"rrr", cmd_rotate_down_double}
	};

	return (list);
}
