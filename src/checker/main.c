/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:30:27 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:21:18 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "pushswap/stack.h"
#include "pushswap/checker.h"
#include "pushswap/core.h"
#include "pushswap/errcode.h"
#include "pushswap/parsing.h"

#include "libft/io.h"
#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"

static void	destroy_instruction(void *cmdset)
{
	ft_array_destroy((t_array) cmdset, free);
}

int	main(int ac, char **av)
{
	t_pushswap	ps;
	char			*line;

	if (ac == 1)
		return (0);
	ps.gc = ft_gc_new();
	if (ps.gc == NULL)
		return (1);
	ps.cmdset = ft_gc_add(ps.gc, ft_array_new(50), &destroy_instruction);
	if (ps.cmdset == NULL)
		exit_program(ps.gc, ERRCODE_BADALLOC);
	ps.stack_a = parse_cli(ac, av, ps.gc);
	while (ft_gnl(STDIN_FILENO, &line) > 0)
		ft_array_append(ps.cmdset, line);
	free(line);
	execute_instruction_set(&ps);
	if (stack_issorted(ps.stack_a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	exit_program(ps.gc, 0);
}
