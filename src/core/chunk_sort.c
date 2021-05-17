#include <stdlib.h>
#include <stdio.h>

#include "libft/gc.h"
#include "libft/array.h"
#include "libft/cstring.h"

#include "pushswap/stack.h"
#include "pushswap/cmd.h"
#include "pushswap/core.h"
#include "pushswap/debug.h"

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

/*
** Prepare the push of the choosen element which is now on the top of the 
** A stack
*/




/*
** Move item at index item_index to the top of the target stack.
** This is done through successive rotate/reverse rotate operations depending
** on the item_index.
** TODO: Further optimization may be needed in the future.
*/

const char	*optimize_cmd(t_pushswap *ps, const char *cmd)
{
	int	need_rr;
	int	max_ind;

	if (ft_strchr(cmd, 'a') != NULL)
	{
		stack_get_max(ps->stack_b, NULL, &max_ind);
		need_rr = max_ind > (int)ps->stack_b->size / 2;
		if (ft_strcmp(cmd, PS_REV_ROT_A) == 0 && max_ind > 0 && need_rr)
			return (PS_REV_ROT_AB);
		if (ft_strcmp(cmd, PS_ROT_A) == 0 && max_ind > 0 && !need_rr)
			return (PS_ROT_AB);
	}
	return (cmd);
}

static void	move_item_to_top(t_pushswap *ps, t_stack *target, int item_index)
{
	const char	*cmd;
	int			offset;

	if ((float)item_index > target->size / 2.0)
	{
		offset = target->size - item_index;
		if (target == ps->stack_a)
			cmd = PS_REV_ROT_A;
		else
			cmd = PS_REV_ROT_B;
	}
	else
	{
		offset = item_index;
		if (target == ps->stack_a)
			cmd = PS_ROT_A;
		else
			cmd = PS_ROT_B;
	}
	while (offset-- > 0)
		//outcmd(ps, optimize_cmd(ps, cmd));
		outcmd(ps, cmd);
}

void	smart_push_to_b(t_pushswap *ps)
{
	int	bmin;
	int	bmax;
	int	bmin_index;
	int	bmax_index;
	int	atopval;

	atopval = stack_peek(ps->stack_a);
	stack_get_min(ps->stack_b, &bmin, &bmin_index);
	stack_get_max(ps->stack_b, &bmax, &bmax_index);

	//move_item_to_top(ps, ps->stack_b, bmax_index);
		
	outcmd(ps, "pb");
}

void	pop_b_in_sorted_order(t_pushswap *ps)
{
	int	item_index;
	int	min;

	while (ps->stack_b->size > 0)
	{
		stack_get_max(ps->stack_b, NULL, &item_index);
		stack_get_min(ps->stack_b, &min, NULL);
		move_item_to_top(ps, ps->stack_b, item_index);
		outcmd(ps, "pa");
	}
}

void	chunk_sort(t_pushswap *ps)
{
	int		chunk_step; 
	int		chunk_id;
	int		top_index;
	int		bot_index;
	int		item_index;
	int		nb_chunk;
	t_chunk	chunk;

	nb_chunk = CHUNK_NB + ps->stack_a->size / 100 + 1;
	chunk_step = (float)(ps->stack_a->max - ps->stack_a->min) / (float)nb_chunk;
	chunk = (t_chunk){ps->stack_a->min, ps->stack_a->min + chunk_step};
	chunk_id = 0;
	while (chunk_id < nb_chunk)
	{
		top_index = scan_stack_a_from_top(ps->stack_a, &chunk);
		bot_index = scan_stack_a_from_bot(ps->stack_a, &chunk);

		/* Nothing left in that chunk, go ahead! */
		if (top_index == -1 && bot_index == -1)
		{
			chunk.lb = chunk.ub + 1;
			chunk.ub = chunk.lb + chunk_step;
			chunk_id++;
			continue ;
		}
		if ((int)ps->stack_a->size - bot_index < top_index)
			item_index = bot_index;
		else
			item_index = top_index;
		move_item_to_top(ps, ps->stack_a, item_index);
		smart_push_to_b(ps);
	}
	//print_stack(ps->stack_b);
	pop_b_in_sorted_order(ps);
}
