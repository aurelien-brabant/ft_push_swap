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
** chunk sort should have placed higher values on the top of stack b, but
** due to the fact we're using chunks, these are not completely sorted.
*/


/*
void	pop_b_in_sorted_order(t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	t_psnode	*cur;
	int	max_index;

	cur = stacks->b->top;
	while (!stack_isempty(stacks->b))
	{
	}
}
*/


void	chunk_sort(t_gc gc, t_cmd *cmdlist, t_stacks *stacks, t_array set)
{
	int		chunk_step; 
	int		chunk_id;
	int		top_index;
	int		bot_index;
	int		item_index;
	t_chunk	chunk;

	chunk_step = (stacks->a->max - stacks->a->min) / CHUNK_NB;
	chunk = (t_chunk){stacks->a->min, stacks->a->min + chunk_step};
	chunk_id = 0;
	while (chunk_id < CHUNK_NB)
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

		/* bottom element can be moved in less moves using rra */
		if ((int)stacks->a->size - bot_index < top_index)
			item_index = bot_index;
		else
			item_index = top_index;
		rotate_to_top_a(cmdlist, stacks, set, item_index);
		outcmd(cmdlist, "pb", stacks, set);
	}
	//pop_b_in_sorted_order();

	/*
	for (size_t chunk_id = 0; chunk_id < CHUNK_NB; ++chunk_id) {
		printf("[C%ld] %d - %d\n", chunk_id, chunk.lb, chunk.ub);
		chunk.lb = chunk.ub + 1;
		chunk.ub = chunk.lb + chunk_step;
	}
	*/
}
