/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:34:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 18:37:48 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "cmd.h"
#include "psstack.h"

void	outcmd(t_cmd *cmdlist, const char *cmd, t_psstack *a,
		t_psstack *b)
{
	ft_printf("%s\n", cmd);
	cmd_exec(cmdlist, cmd, a, b);
}
