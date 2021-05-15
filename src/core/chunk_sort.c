#include <stdlib.h>
#include <stdio.h>

#include "libft/gc.h"
#include "libft/array.h"

#include "pushswap/stack.h"
#include "pushswap/cmd.h"
#include "pushswap/core.h"

/* 1 means scan from the top of the stack, -1 means from the bottom. */

int	scan_stack_a_from_bot(t_stack *a, t_chunk *chunk)
{
	int		index;
	t_psnode	*cur;
	
	index = a->size - 1;
	cur = a->bot;
	while (cur != NULL)
	{
		if (cur->val >= chunk->lb && cur->val <= chunk->ub)
			return (index);
		cur = cur->next;
		--index;
	}
	return (-1);
}

int	scan_stack_a_from_top(t_stack *a, t_chunk *chunk)
{
	int		index;
	t_psnode	*cur;
	
	index = 0;
	cur = a->top;
	while (cur != NULL)
	{
		if (cur->val >= chunk->lb && cur->val <= chunk->ub)
			return (index);
		cur = cur->prev;
		++index;
	}
	return (-1);
}

void	rotate_to_top_a(t_cmd *cmdlist, t_stacks *stacks, t_array set, int item_index)
{
	char	*cmd;
	int	offset;
	int	i;

	if (item_index == 0)
		return ;
	if (item_index > (int)stacks->a->size / 2)
	{
		cmd = "rra";
		offset = stacks->a->size - item_index;
	}
	else
	{
		offset = item_index;
		cmd = "ra";
	}
	i = 0;
	while (i++ < offset)
		outcmd(cmdlist, cmd, stacks, set);
}

/*
** Prepare the push of the choosen element which is now on the top of the 
** A stack
*/

void	smart_push_to_b(t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	int	bmin;
	int	bmax;
	int	bmin_index;
	int	bmax_index;
	int	atopval;

	atopval = stack_peek(stacks->a);
	stack_get_min(stacks->b, &bmin, &bmin_index);
	stack_get_max(stacks->b, &bmax, &bmax_index);
		
	/* if atopval < min we need to put this small value at the very bottom of the B stack */
	if (atopval < bmin)
	{
		outcmd(cmdlist, "pb", stacks, set);
		/* move atopval to the bottom of B stack as it is below the minimum */
		outcmd(cmdlist, "rb", stacks, set);
		return ;
	}
	outcmd(cmdlist, "pb", stacks, set);
}

void	pop_b_in_sorted_order(t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	int		i;
	int	item_index;
	int	offset;
	char	*cmd;

	while (stacks->b->size > 0)
	{
		stack_get_max(stacks->b, NULL, &item_index);
		if (item_index > (int)stacks->b->size / 2)
		{
			offset = stacks->b->size - item_index;
			cmd = "rrb";
		}
		else
		{
			offset = item_index;
			cmd = "rb";
		}
		i = 0;
		while (i++ < offset)
			outcmd(cmdlist, cmd, stacks, set);
		outcmd(cmdlist, "pa", stacks, set);
	}
}

void	chunk_sort(t_gc gc, t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	int		chunk_step; 
	int		chunk_id;
	int		top_index;
	int		bot_index;
	int		item_index;
	int		nb_chunk;
	t_chunk	chunk;

	nb_chunk = CHUNK_NB + stacks->a->size / 100 + 1;
	chunk_step = (stacks->a->max - stacks->a->min) / nb_chunk;
	chunk = (t_chunk){stacks->a->min, stacks->a->min + chunk_step};
	chunk_id = 0;
	while (chunk_id < nb_chunk)
	{
		top_index = scan_stack_a_from_top(stacks->a, &chunk);
		bot_index = scan_stack_a_from_bot(stacks->a, &chunk);

		/* Nothing left in that chunk, go ahead! */
		if (top_index == -1 && bot_index == -1)
		{
			chunk.lb = chunk.ub + 1;
			chunk.ub = chunk.lb + chunk_step;
			chunk_id++;
			continue ;
		}
		if ((int)stacks->a->size - bot_index < top_index)
			item_index = bot_index;
		else
			item_index = top_index;
		rotate_to_top_a(cmdlist, stacks, set, item_index);
		smart_push_to_b(cmdlist, stacks, set);
	}
	pop_b_in_sorted_order(cmdlist, stacks, set);
}
