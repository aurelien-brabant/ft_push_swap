/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_set.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 01:15:15 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:26:39 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/array.h"
#include "libft/io.h"

#include "pushswap/stack.h"
#include "pushswap/cmd.h"
#include "pushswap/core.h"
#include "pushswap/errcode.h"

void	execute_instruction_set(t_array set, t_stacks *stacks, t_gc gc)
{
	t_cmd			*cmdlist;
	char			*instruction;
	size_t			i;

	cmdlist = cmd_getlist();
	stacks->b = ft_gc_add(gc, stack_new(), stack_destroy);
	i = 0;
	while (i < ft_array_length(set))
	{
		instruction = ft_array_get(set, i++);
		if (instruction == NULL || !cmd_exec(cmdlist, instruction, stacks))
			exit_program(gc, ERRCODE_UNSUPPORTED_INSTRUCTION);
	}
}
