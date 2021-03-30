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
#include "pshswp_stack.h"

void	outcmd(t_cmd *cmdlist, const char *cmd, t_pshswp_stack *a,
		t_pshswp_stack *b)
{
	ft_printf("%s\n", cmd);
	cmd_exec(cmdlist, cmd, a, b);
}
