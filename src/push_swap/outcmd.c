/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:34:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:37:25 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/array.h"
#include "cmd.h"
#include "psstack.h"

void	outcmd(t_cmd *cmdlist, const char *cmd, t_stacks *stacks, t_array set)
{
	ft_array_append(set, (void *)cmd);
	cmd_exec(cmdlist, cmd, stacks);
}
