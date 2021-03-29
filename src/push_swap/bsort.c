/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:14 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 18:57:54 by abrabant         ###   ########.fr       */
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

	top = stack_size(a) - 1;
	while (top > 0)
	{
		if (stack_lookup(a, top) > stack_lookup(a, top - 1))
		{
			while (stack_size(a) - 1 > top)
			{
				outcmd("pb");
				cmd_exec(cmdlist, "pb", a, b);
			}
			outcmd("sa");
			cmd_exec(cmdlist, "sa", a, NULL);
			while (!stack_isempty(b))
			{
				outcmd("pa");
				cmd_exec(cmdlist, "pa", a, b);
			}
		}
		--top;
	}
	cmd_exec(cmdlist, "rra", a, NULL);
}
