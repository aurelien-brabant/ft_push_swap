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

void	execute_instruction_set(t_pushswap *ps)
{
	char			*instruction;
	size_t			i;

	ps->cmdlist = cmd_getlist();
	ps->stack_b = ft_gc_add(ps->gc, stack_new(), stack_destroy);
	i = 0;
	while (i < ft_array_length(ps->cmdset))
	{
		instruction = ft_array_get(ps->cmdset, i++);
		if (instruction == NULL || !cmd_exec(ps, instruction))
			exit_program(ps->gc, ERRCODE_UNSUPPORTED_INSTRUCTION);
	}
}
