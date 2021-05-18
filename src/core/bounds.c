#include "pushswap/pscore.h"

void	get_bounds(t_pushswap *ps, t_bounds *bounds, size_t div_by)
{
	int		step;
	size_t	i;
	size_t	lower_ind;
	size_t	upper_ind;

	step = ps->stack_a->size / div_by;
	i = 0;
	lower_ind = 0;
	upper_ind = step;
	while (i < div_by)
	{
		bounds[i].lower = ps->slst[lower_ind];
		if (i + 1 == div_by)
			bounds[i].upper = ps->slst[ps->stack_a->size - 1];
		else
			bounds[i].upper = ps->slst[upper_ind];
		lower_ind = upper_ind + 1;
		upper_ind += step;
		++i;
	}
}
