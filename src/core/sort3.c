/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:23:23 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:42:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/cmd.h"
#include "pushswap/core.h"

void	sort3(t_pushswap *ps)
{
	int	nb0;
	int	nb1;
	int	nb2;

	nb0 = gsv(ps->stack_a, 0);
	nb1 = gsv(ps->stack_a, 1);
	nb2 = gsv(ps->stack_a, 2);
	if (nb2 > nb0 && nb0 > nb1)
		outcmd(ps, "ra");
	else if (nb2 > nb1 && nb1 > nb0)
	{
		outcmd(ps, "sa");
		outcmd(ps, "rra");
	}
	else if (nb1 > nb0 && nb0 > nb2)
	{
		outcmd(ps, "rra");
		outcmd(ps, "sa");
	}
	else if (nb2 > nb1 && nb0 > nb2)
		outcmd(ps, "sa");
	else if (nb1 > nb2 && nb2 > nb0)
		outcmd(ps, "rra");
}
