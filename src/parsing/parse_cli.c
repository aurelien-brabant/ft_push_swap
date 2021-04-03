/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:29:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 13:23:27 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft/gc.h"
#include "libft/array.h"
#include "libft/string.h"

#include "pscore.h"
#include "psstack.h"
#include "errcode.h"

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
		if (nb > INT_MAX || nb < INT_MIN)
			exit_program(gc, ERRCODE_INT_OOB);
		if (stack_search(a, nb) != -1)
			exit_program(gc, ERRCODE_STACK_DUPLICATES);
		stack_push(a, nb);
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

t_psstack	*parse_cli(int ac, char **av, t_gc gc)
{
	t_psstack	*a;

	a = ft_gc_add(gc, stack_new(), stack_destroy);
	if (a == NULL)
		ac = 1;
	while (--ac > 0 && parse_arg(av[ac], gc, a))
		;
	return (a);
}
