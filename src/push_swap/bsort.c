/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:14 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 14:34:34 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "pshswp_stack.h"
#include "push_swap.h"

/*
** Implementation of bubble sort using push_swap instruction language.
** This sorting algorithm is not great but simple, it is here for
** demonstration purpose.
**
** Stack B is not needed for that one.
*/

void	bsort(t_cmd *cmdlist, t_pshswp_stack *a)
{
	size_t	top;

	top = stack_size(a) - 1;
	while (top > 0)
	{
		if (stack_lookup(a, top) > stack_lookup(a, top - 1))
		{
			cmd_exec(cmdlist, PS_SWAP_A, a, NULL);
			outcmd(PS_SWAP_A);
			top = stack_size(a) - 1;
			continue ;
		}
		--top;
	}
}
