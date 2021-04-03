/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:14:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 14:22:29 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "push_swap.h"
#include "psstack.h"
#include "pscore.h"
#include "errcode.h"
#include "parsing.h"

#include "libft/gc.h"
#include "libft/string.h"
#include "libft/array.h"

int	main(int ac, char **av)
{
	t_gc		gc;
	t_psstack	*a;

	gc = ft_gc_new();
	if (gc == NULL)
		return (ERRCODE_BADALLOC);
	a = parse_cli(ac, av, gc);
	generate(gc, a);
	ft_gc_destroy(gc);
	return (0);
}
