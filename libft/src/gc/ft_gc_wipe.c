/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_wipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:21:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 22:21:50 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/internal/gc_int.h"
#include "libft/array.h"

static int	wipe(void *el, size_t i, void *triggers)
{
	void	(*trigger)();

	trigger = ft_array_get(triggers, i);
	trigger(el);
	return (0);
}

void	ft_gc_wipe(t_gc_int *gc)
{
	ft_array_foreach(gc->collector, wipe, gc->triggers);
	ft_array_set_length(gc->collector, 0);
	ft_array_set_length(gc->triggers, 0);
}
