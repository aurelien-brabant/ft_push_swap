#include "pushswap/pscore.h"

void	get_bounds(t_pushswap *ps, t_bounds *bounds, size_t bounds_nb)
{
	int		step;
	size_t	i;
	size_t	lower_ind;
	size_t	upper_ind;

	i = 0;
	step = ps->stack_a->size / bounds_nb;
	lower_ind = 0;
	upper_ind = step;
	while (i < bounds_nb)
	{
		bounds[i].size = 0;
		bounds[i].nb = i;
		bounds[i].lower = ps->slst[lower_ind];
		if (i + 1 == bounds_nb)
			bounds[i].upper = ps->slst[ps->stack_a->size - 1];
		else
		{
			bounds[i].upper = ps->slst[upper_ind];
			bounds[i].size = upper_ind - lower_ind + 1;
		}
		lower_ind = upper_ind + 1;
		upper_ind = lower_ind + step;
		++i;
	}
}
