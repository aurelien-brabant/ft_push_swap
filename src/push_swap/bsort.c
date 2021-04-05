/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:14 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:40:25 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cmd.h"
#include "psstack.h"
#include "push_swap.h"

/*
 ** Implementation of bubble sort using push_swap instruction language.
 ** This sorting algorithm is naive and should not be actually used.
 ** It is here just for demonstration purpose.
 **
 ** Stack B is not needed for that one.
 */

void	bsort(t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	size_t	max_pass;
	size_t	top;
	size_t	pass;

	max_pass = stack_size(stacks->a);
	top = max_pass;
	pass = 0;
	while (pass < max_pass - 1)
	{
		top = max_pass;
		while (top-- > pass + 1)
		{
			if (stack_lookup(stacks->a, top) > stack_lookup(stacks->a, top - 1))
			{
				while (stack_size(stacks->a) - 1 > top)
					outcmd(cmdlist, "pb", stacks, set);
				outcmd(cmdlist, "sa", stacks, set);
				if (top - 1 > 0)
					outcmd(cmdlist, "pb", stacks, set);
			}
		}
		while (!stack_isempty(stacks->b))
			outcmd(cmdlist, PS_PUSH_A, stacks, set);
		++pass;
	}
}
