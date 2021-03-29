/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:01:12 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 14:32:16 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "cmd.h"
#include "libft/io.h"
#include "push_swap.h"
#include "pshswp_stack.h"

void	outcmd(const char *cmd)
{
	ft_putstr_fd(cmd, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	generate(t_pshswp_stack *a)
{
	t_pshswp_stack	*b;
	t_cmd			*cmdlist;

	cmdlist = cmd_getlist();
	(void)a;
	b = stack_new();
	if (b == NULL)
		return ;
	bsort(cmdlist, a);
}
