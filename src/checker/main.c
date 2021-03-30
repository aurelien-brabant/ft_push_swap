/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:14:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 17:33:32 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "cmd.h"
#include "pshswp_stack.h"
#include "checker.h"

#include "libft/io.h"
#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"

static int	reverse_int_push(t_array split, t_pshswp_stack *a)
{
	long long	nb;
	size_t		i;

	i = ft_array_length(split);
	while (i-- > 0)
	{
		nb = ft_string_btoll((t_string)ft_array_get(split, i), 10);
		stack_push((t_pshswp_stack *)a, nb);
	}
	return (0);
}

static void	destroy_split(void *split)
{
	ft_array_destroy((t_array)split, (void (*)(void *))ft_string_destroy);
}

static bool	parse_arg(char *av, t_gc gc, t_pshswp_stack *a)
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
	ft_gc_add(gc, split, destroy_split);
	reverse_int_push(split, a);
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
	t_pshswp_stack	*a;

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
