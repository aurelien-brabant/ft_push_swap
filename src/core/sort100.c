/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:16:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 21:04:27 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft/cstring.h"

#include "pushswap/debug.h"
#include "pushswap/pscore.h"
#include "pushswap/stack.h"
#include "pushswap/cmd.h"

static int	get_median(int *a, size_t size)
{
	int	mid;

	mid = size / 2;
	if (size % 2 == 0)
		return ((a[mid] + a[mid + 1]) / 2);
	return (a[mid]);
}

/*
** Optimized sorting for 100 items.
** CURRRENT_STATE: in most cases sorting is done with < 900 instructions.
** Works for any number of items, but is not super efficient.
*/

void	sort100(t_pushswap *ps)
{
	int	median;
}
