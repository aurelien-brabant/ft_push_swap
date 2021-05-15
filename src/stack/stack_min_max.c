#include <limits.h>

#include "pushswap/stack.h"

int	stack_get_max_index(t_stack *stack)
{
	t_psnode	*cur;
	int		max;
	int		max_index;
	int		index;
	
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
	return (max_index);
}

int	stack_get_min_index(t_stack *stack)
{
	t_psnode	*cur;
	int		min;
	int		min_index;
	int		index;
	
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
	return (min_index);
}
