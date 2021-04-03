/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:30:27 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 11:30:30 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "cmd.h"
#include "psstack.h"
#include "checker.h"
#include "pscore.h"
#include "errcode.h"

#include "libft/io.h"
#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"

static int	reverse_int_push(t_array split, t_psstack *a, t_gc gc)
{
	long long	nb;
	bool		err;
	size_t		i;

	err = false;
	i = ft_array_length(split);
	while (i-- > 0)
	{
		nb = ft_string_btoll((t_string)ft_array_get(split, i), 10, &err);
		if (err)
			exit_program(gc, ERRCODE_INVALID_NB);
		stack_push((t_psstack *)a, nb);
	}
	return (0);
}

static bool	parse_arg(char *av, t_gc gc, t_psstack *a)
{
	t_string		arg;
	t_array			split;

	arg = ft_gc_add(gc, ft_string_new_cstr(av),
			(void (*)(void *))ft_string_destroy);
	if (arg == NULL)
		return (false);
	split = ft_string_split(arg, " ");
	if (split == NULL)
		return (false);
	ft_gc_add(gc, split, ft_string_destroy_split);
	reverse_int_push(split, a, gc);
	return (true);
}

static void	destroy_instruction_set(void *set)
{
	ft_array_destroy((t_array) set, free);
}

int	main(int ac, char **av)
{
	t_gc			gc;
	t_array			set;
	char			*line;
	t_psstack	*a;

	gc = ft_gc_new();
	if (gc == NULL)
		return (1);
	set = ft_gc_add(gc, ft_array_new(20), destroy_instruction_set);
	a = ft_gc_add(gc, stack_new(), stack_destroy);
	if (set == NULL || a == NULL)
		ac = 1;
	while (--ac > 0 && parse_arg(av[ac], gc, a))
		;
	while (ft_gnl(STDIN_FILENO, &line) > 0)
		ft_array_append(set, line);
	free(line);
	execute_instruction_set(set, a);
	if (stack_issorted(a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_gc_destroy(gc);
	return (0);
}
