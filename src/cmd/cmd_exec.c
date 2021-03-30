/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:04:28 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 14:19:27 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

#include "pshswp_stack.h"
#include "cmd.h"
#include "debug.h"

#include "libft/cstring.h"

bool	cmd_exec(t_cmd *cmdlist, const char *cmd, t_pshswp_stack *a,
		t_pshswp_stack *b)
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
			cmdlist[mid].trigger(a, b);
			return (true);
		}
		if (cmp_ret > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (false);
}
