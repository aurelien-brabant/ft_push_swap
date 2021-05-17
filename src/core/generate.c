/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:01:12 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/17 10:27:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft/io.h"
#include "libft/gc.h"
#include "libft/array.h"
#include "libft/core.h"

#include "pushswap/cmd.h"
#include "pushswap/stack.h"
#include "pushswap/core.h"

void	generate(t_pushswap *ps)
{
	ps->cmdlist = cmd_getlist();
	ps->stack_b = ft_gc_add(ps->gc, stack_new(), stack_destroy);
	ps->stack_b = stack_new();
	if (ps->stack_b == NULL)
		return ;
	if (stack_issorted(ps->stack_a))
		return ;
	ps->slst = stack_to_array(ps->stack_a);
	ft_quick_sort(ps->slst, ps->stack_a->size, sizeof (int), &ft_gcmp_int);
	//for (int i = 0; i < ps->stack_a->size; ++i)
		//printf("%d, ", ps->slst[i]);
	/*if (stack_size(stacks->a) == 3)
		sort3(cmdlist, stacks, set);*/
	//chunk_sort(ps);
	sort100(ps);
}
