#include <limits.h>

#include "pushswap/stack.h"

void	stack_get_max(t_stack *stack, int *hold_max, int *hold_max_index)
{
	t_psnode	*cur;
	int			max;
	int			max_index;
	int			index;

	max = INT_MIN;
	max_index = -1;
	index = 0;
	cur = stack->top;
	while (cur != NULL)
	{
		if (cur->val > max)
		{
			max = cur->val;
			max_index = index;
		}
		cur = cur->prev;
		++index;
	}
	if (hold_max != NULL)
		*hold_max = max;
	if (hold_max_index != NULL)
		*hold_max_index = max_index;
}

void	stack_get_min(t_stack *stack, int *hold_min, int *hold_min_index)
{
	t_psnode	*cur;
	int			min;
	int			min_index;
	int			index;

	min = INT_MAX;
	min_index = -1;
	index = 0;
	cur = stack->top;
	while (cur != NULL)
	{
		if (cur->val < min)
		{
			min = cur->val;
			min_index = index;
		}
		cur = cur->prev;
		++index;
	}
	if (hold_min != NULL)
		*hold_min = min;
	if (hold_min_index != NULL)
		*hold_min_index = min_index;
}
