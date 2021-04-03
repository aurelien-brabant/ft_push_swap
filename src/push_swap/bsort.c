/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:14 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 19:07:09 by abrabant         ###   ########.fr       */
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

void	bsort(t_cmd *cmdlist, t_psstack *a, t_psstack *b)
{
	size_t	max_pass;
	size_t	top;
	size_t	pass;

	max_pass = stack_size(a);
	top = max_pass;
	pass = 0;
	while (pass < max_pass - 1)
	{
		top = max_pass;
		while (top-- > pass + 1)
		{
			if (stack_lookup(a, top) > stack_lookup(a, top - 1))
			{
				while (stack_size(a) - 1 > top)
					outcmd(cmdlist, "pb", a, b);
				outcmd(cmdlist, "sa", a, b);
				if (top - 1 > 0)
					outcmd(cmdlist, "pb", a, b);
			}
		}
		while (!stack_isempty(b))
			outcmd(cmdlist, PS_PUSH_A, a, b);
		++pass;
	}
}
