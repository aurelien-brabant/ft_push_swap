/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:14:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/17 10:25:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"
#include "pushswap/core.h"
#include "pushswap/cmd.h"
#include "pushswap/errcode.h"
#include "pushswap/parsing.h"

#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"
#include "libft/io.h"

static int	print_instruction(void *instruction)
{
	ft_printf("%s\n", (char *) instruction);
	return (0);
}

int	main(int ac, char **av)
{
	t_pushswap	ps;

	ps.gc = ft_gc_new();
	if (ps.gc == NULL)
		return (ERRCODE_BADALLOC);
	ps.cmdset = ft_gc_add(ps.gc, ft_array_new(50), ft_array_destroy);
	if (ps.cmdset == NULL)
		exit_program(ps.gc, ERRCODE_BADALLOC);
	ps.stack_a = parse_cli(ac, av, ps.gc);
	generate(&ps);
	ft_array_foreach(ps.cmdset, print_instruction, NULL);
	exit_program(ps.gc, 0);
}
