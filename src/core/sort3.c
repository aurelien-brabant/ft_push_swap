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

#include "pushswap/push_swap.h"
#include "pushswap/cmd.h"

void	sort3(t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	int	nb0;
	int	nb1;
	int	nb2;

	nb0 = gsv(stacks->a, 0);
	nb1 = gsv(stacks->a, 1);
	nb2 = gsv(stacks->a, 2);
	if (nb2 > nb0 && nb0 > nb1)
		outcmd(cmdlist, "ra", stacks, set);
	else if (nb2 > nb1 && nb1 > nb0)
	{
		outcmd(cmdlist, "sa", stacks, set);
		outcmd(cmdlist, "rra", stacks, set);
	}
	else if (nb1 > nb0 && nb0 > nb2)
	{
		outcmd(cmdlist, "rra", stacks, set);
		outcmd(cmdlist, "sa", stacks, set);
	}
	else if (nb2 > nb1 && nb0 > nb2)
		outcmd(cmdlist, "sa", stacks, set);
	else if (nb1 > nb2 && nb2 > nb0)
		outcmd(cmdlist, "rra", stacks, set);
}
