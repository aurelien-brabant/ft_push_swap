/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:01:12 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:30:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/io.h"
#include "libft/gc.h"
#include "libft/array.h"

#include "pushswap/cmd.h"
#include "pushswap/push_swap.h"
#include "pushswap/stack.h"
#include "pushswap/core.h"

void	generate(t_gc gc, t_stacks *stacks, t_array set)
{
	t_cmd		*cmdlist;

	cmdlist = cmd_getlist();
	stacks->b = ft_gc_add(gc, stack_new(), stack_destroy);
	if (stacks->b == NULL)
		return ;
	if (stack_issorted(stacks->a))
		return ;
	/*if (stack_size(stacks->a) == 3)
		sort3(cmdlist, stacks, set);*/
	chunk_sort(gc, cmdlist, stacks, set);
}
