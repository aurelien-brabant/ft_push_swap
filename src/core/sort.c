/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:16:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/19 12:19:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/cstring.h"

#include "pushswap/pscore.h"
#include "pushswap/pstypes.h"
#include "pushswap/stack.h"
#include "pushswap/cmd.h"

/*
** Global sorting function, always used when stack size is greater than five.
** Split is optimized to work the best possible with a stack size of 100 and
** 500 though.
*/

static size_t	get_bound_nb(t_stack *a)
{
	if (a->size == 500)
		return (SORT500_SPLIT_NB);
	if (a->size == 100)
		return (SORT100_SPLIT_NB);
	else
		return (2);
}

void	sort(t_pushswap *ps)
{
	t_bounds	*bounds;
	size_t		bounds_nb;
	size_t		i;

	bounds_nb = get_bound_nb(ps->stack_a);
	bounds = ft_gc_add(ps->gc, malloc(sizeof(*bounds) * bounds_nb), &free);
	if (bounds == NULL)
		return ;
	get_bounds(ps, bounds, bounds_nb);
	i = 0;
	while (i < bounds_nb)
	{
		split(ps, bounds[i], ps->stack_a->size / bounds_nb + 1);
		insert_all(ps, bounds[i]);
		++i;
	}
}
