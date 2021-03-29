/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:04:28 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 19:32:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

#include "pshswp_stack.h"
#include "cmd.h"
#include "debug.h"

#include "libft/cstring.h"

void	cmd_exec(t_cmd *cmdlist, const char *cmd, t_pshswp_stack *a,
		t_pshswp_stack *b)
{
	uint8_t	low;
	uint8_t	mid;
	uint8_t	high;
	int		cmp_ret;

	low = 0;
	high = CMD_NB - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cmp_ret = ft_strcmp(cmd, cmdlist[mid].name);
		if (cmp_ret == 0)
		{
			cmdlist[mid].trigger(a, b);
			//print_stacks(a, b);
		}
		if (cmp_ret > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
}
