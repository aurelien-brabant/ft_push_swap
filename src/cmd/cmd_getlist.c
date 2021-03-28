/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:44:33 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 16:44:14 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "pshswp_stack.h"

/*
** NOTE: Commands are lexiographically sorted to make use of a binary search
** algorithm in cmd_exec.
*/

t_cmd	*cmd_getlist(void)
{
	static t_cmd	list[CMD_NB] = {{"pa", cmd_push_a}, {"pb", cmd_push_b},
		{"ra", stack_rotate_up}, {"rb", stack_rotate_up},
		{"rr", cmd_rotate_up_double}, {"rra", stack_rotate_down},
		{"rrb", stack_rotate_down}, {"rrr", cmd_rotate_down_double},
		{"sa", cmd_swap_a}, {"sb", cmd_swap_b}, {"ss", cmd_swap_double}
	};

	return (list);
}
