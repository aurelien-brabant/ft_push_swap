/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_set.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 01:15:15 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 01:48:17 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/array.h"
#include "libft/io.h"

#include "pshswp_stack.h"
#include "cmd.h"

void	execute_instruction_set(t_array set, t_pshswp_stack *a)
{
	t_cmd			*cmdlist;
	char			*instruction;
	t_pshswp_stack	*b;
	size_t			i;

	cmdlist = cmd_getlist();
	b = stack_new();
	i = 0;
	while (i < ft_array_length(set))
	{
		instruction = ft_array_get(set, i++);
		if (instruction == NULL || !cmd_exec(cmdlist, instruction, a, b))
		{
			ft_dprintf(STDERR_FILENO, "[\033[0;31mX\033[0m] Instruction \"%s\" "
					"is not supported. Stopping execution here.\n", instruction);
			break ;
		}
	}
}
