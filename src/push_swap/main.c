/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:14:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 12:10:04 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "push_swap.h"
#include "psstack.h"
#include "pscore.h"

#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"

static int	reverse_int_push(t_array split, t_psstack *a, t_gc gc)
{
	long long	nb;
	size_t		i;
	bool		err;

	i = ft_array_length(split);
	while (i-- > 0)
	{
		nb = ft_string_btoll((t_string)ft_array_get(split, i), 10, &err);
		if (err)
			exit_program(gc, 1);
		stack_push((t_psstack *)a, nb);
	}
	return (0);
}

static void	destroy_split(void *split)
{
	ft_array_destroy((t_array)split, (void (*)(void *))ft_string_destroy);
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
	ft_gc_add(gc, split, destroy_split);
	reverse_int_push(split, a, gc);
	return (true);
}

int	main(int ac, char **av)
{
	t_gc			gc;
	t_psstack	*a;

	gc = ft_gc_new();
	if (gc == NULL)
		return (1);
	a = ft_gc_add(gc, stack_new(), stack_destroy);
	if (a == NULL)
		ac = 1;
	while (--ac > 0 && parse_arg(av[ac], gc, a))
		;
	generate(gc, a);
	ft_gc_destroy(gc);
	return (0);
}
