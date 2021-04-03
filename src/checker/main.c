/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:30:27 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 12:55:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "psstack.h"
#include "checker.h"
#include "pscore.h"
#include "errcode.h"
#include "parsing.h"

#include "libft/io.h"
#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"

static void	destroy_instruction_set(void *set)
{
	ft_array_destroy((t_array) set, free);
}

int	main(int ac, char **av)
{
	t_gc			gc;
	t_array			set;
	char			*line;
	t_psstack		*a;

	gc = ft_gc_new();
	if (gc == NULL)
		return (1);
	set = ft_gc_add(gc, ft_array_new(50), destroy_instruction_set);
	if (set == NULL)
		exit_program(gc, ERRCODE_BADALLOC);
	a = parse_cli(ac, av, gc);
	while (ft_gnl(STDIN_FILENO, &line) > 0)
		ft_array_append(set, line);
	free(line);
	execute_instruction_set(set, a);
	if (stack_issorted(a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	exit_program(gc, 0);
}
