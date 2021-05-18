/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:16:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 17:18:32 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft/cstring.h"

#include "pushswap/debug.h"
#include "pushswap/pscore.h"
#include "pushswap/stack.h"
#include "pushswap/cmd.h"

/*
** Optimized sorting for 500 items.
** CURRRENT_STATE: in most cases sorting is done with < 900 instructions.
** Works for any number of items, but is not super efficient.
*/

void	sort500(t_pushswap *ps)
{
	t_bounds	bounds[6];
	size_t		i;

	get_bounds(ps, bounds, 6);
	i = 0;
	while (i < 6)
	{
		split(ps, bounds[i]);
		insert_all(ps, bounds[i]);
		++i;
	}
}
