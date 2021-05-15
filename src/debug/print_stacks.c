/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:09:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:21:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"
#include "pushswap/core.h"
#include "libft/io.h"

/*
static size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
*/

/*
void	print_stacks(t_psstack *a, t_psstack *b)
{
	size_t	topa;
	size_t	topb;
	size_t	size;

	size = max(stack_size(a), stack_size(b));
	topa = stack_size(a);
	topb = stack_size(b);
	ft_putstr_fd("|---|---|\n", 1);
	ft_putstr_fd("| A | B |\n", 1);
	ft_putstr_fd("|---|---|\n", 1);
	while (size-- > 0)
	{
		if (size < topa)
			ft_printf("| %d |", a->data[size]);
		else
			ft_putstr_fd("|   |", 1);
		if (size < topb)
			ft_printf(" %d |\n", b->data[size]);
		else
			ft_putstr_fd("   |\n", 1);
	}
	ft_putstr_fd("|---|---|\n", 1);
}
*/

#include <stdio.h>

void	print_chunks(t_stacks *stacks)
{
	int	chunk_step;
	t_chunk	chunk;
	
	chunk_step = (stacks->a->max - stacks->a->min) / (CHUNK_NB + stacks->a->size / 100);
	chunk = (t_chunk){stacks->a->min, stacks->a->min + chunk_step};

	for (size_t chunk_id = 0; chunk_id < CHUNK_NB; ++chunk_id) {
		printf("[C%ld] %d - %d\n", chunk_id, chunk.lb, chunk.ub);
		chunk.lb = chunk.ub + 1;
		chunk.ub = chunk.lb + chunk_step;
	}
}
