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

#include "pushswap/cmd.h"
#include "pushswap/stack.h"

void	outcmd(t_pushswap *ps, const char *cmd)
{
	ft_array_append(ps->cmdset, (void *)cmd);
	cmd_exec(ps, cmd);
}
