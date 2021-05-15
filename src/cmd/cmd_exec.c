/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:04:28 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:37:57 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

#include "libft/cstring.h"

#include "pushswap/stack.h"
#include "pushswap/cmd.h"
#include "pushswap/debug.h"

/*
** Retrieve and execute the specified command.
** cmd_exec is making use of a simple binsearch algorithm to optimize speed.
*/

bool	cmd_exec(t_cmd *cmdlist, const char *cmd, t_stacks *stacks)
{
	int8_t	low;
	int8_t	mid;
	int8_t	high;
	int		cmp_ret;

	low = 0;
	high = CMD_NB - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cmp_ret = ft_strcmp(cmd, cmdlist[mid].name);
		if (cmp_ret == 0)
		{
			cmdlist[mid].trigger(stacks->a, stacks->b);
			return (true);
		}
		if (cmp_ret > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (false);
}
