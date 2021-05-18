#include "pushswap/pscore.h"
#include "pushswap/stack.h"

bool	is_oob(int v, t_bounds bounds)
{
	return (!(v >= bounds.lower && v <= bounds.upper));
}

int	select_value_by_index(t_stack *stack)
{
	int	min_ind;
	int	max_ind;
	int	min_offset;
	int	max_offset;

	stack_get_min(stack, NULL, &min_ind);
	stack_get_max(stack, NULL, &max_ind);
	if (min_ind > (int)stack->size / 2)
		min_offset = stack->size - min_ind;
	else
		min_offset = min_ind;
	if (max_ind > (int)stack->size / 2)
		max_offset = stack->size - max_ind;
	else
		max_offset = max_ind;
	if (max_offset <= min_offset)
		return (max_ind);
	return (min_ind);
}
