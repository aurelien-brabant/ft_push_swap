/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:14 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 14:18:04 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cmd.h"
#include "pshswp_stack.h"
#include "push_swap.h"

/*
** Implementation of bubble sort using push_swap instruction language.
** This sorting algorithm is naive and should not be actually used.
** It is here just for demonstration purpose.
**
** Stack B is not needed for that one.
*/

void	bsort(t_cmd *cmdlist, t_pshswp_stack *a, t_pshswp_stack *b)
{
	size_t	top;

	top = stack_size(a);
	while (top-- > 0)
	{
		if (stack_lookup(a, top) > stack_lookup(a, top - 1))
		{
			while (stack_size(a) - 1 > top)
			{
				outcmd(PS_PUSH_B);
				cmd_exec(cmdlist, PS_PUSH_B, a, b);
			}
			outcmd(PS_SWAP_A);
			cmd_exec(cmdlist, PS_SWAP_A, a, b);
			while (!stack_isempty(b))
			{
				outcmd(PS_PUSH_A);
				cmd_exec(cmdlist, PS_PUSH_A, a, b);
			}
			top = stack_size(a);
			continue ;
		}
	}
}
