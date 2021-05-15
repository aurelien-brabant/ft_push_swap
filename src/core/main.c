/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:14:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:46:34 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/cmd.h"
#include "pushswap/push_swap.h"
#include "pushswap/stack.h"
#include "pushswap/pscore.h"
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
	t_gc		gc;
	t_stacks	stacks;
	t_array		set;

	gc = ft_gc_new();
	if (gc == NULL)
		return (ERRCODE_BADALLOC);
	set = ft_gc_add(gc, ft_array_new(50), ft_array_destroy);
	if (set == NULL)
		exit_program(gc, ERRCODE_BADALLOC);
	stacks.a = parse_cli(ac, av, gc);
	generate(gc, &stacks, set);
	ft_array_foreach(set, print_instruction, NULL);
	exit_program(gc, 0);
}
