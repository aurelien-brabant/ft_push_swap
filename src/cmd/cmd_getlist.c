/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:44:33 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/20 11:25:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/cmd.h"
#include "pushswap/stack.h"

/*
** NOTE: Commands are and must be lexiographically sorted to make use
** of the binary search algorithm in cmd_exec.
*/

t_cmd	*cmd_getlist(void)
{
	static t_cmd	list[CMD_NB] = {{PS_PUSH_A, cmd_push_a},
		{PS_PUSH_B, cmd_push_b}, {PS_ROT_A, cmd_rotate_up_a},
		{PS_ROT_B, cmd_rotate_up_b}, {PS_ROT_AB, cmd_rotate_up_double},
		{PS_REV_ROT_A, cmd_rotate_down_a}, {PS_REV_ROT_B, cmd_rotate_down_b},
		{PS_REV_ROT_AB, cmd_rotate_down_double}, {PS_SWAP_A, cmd_swap_a},
		{PS_SWAP_B, cmd_swap_b}, {PS_SWAP_AB, cmd_swap_double}
	};

	return (list);
}
