#include "pushswap/cmd.h"
#include "pushswap/pscore.h"
#include "pushswap/stack.h"

void	sort4(t_pushswap *ps)
{
	int	inserted;

	outcmd(ps, PS_PUSH_B);
	sort3(ps);
	inserted = stack_peek(ps->stack_b);
	if (inserted > gsv(ps->stack_a, 1) && inserted < gsv(ps->stack_a, 2))
	{
		outcmd(ps, PS_REV_ROT_A);
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_ROT_A);
		outcmd(ps, PS_ROT_A);
		return ;
	}
	outcmd(ps, PS_PUSH_A);
	if (inserted < gsv(ps->stack_a, 1))
		return ;
	else if (inserted > gsv(ps->stack_a, 3))
		outcmd(ps, "ra");
	else if (inserted > gsv(ps->stack_a, 1) && inserted < gsv(ps->stack_a, 2))
		outcmd(ps, "sa");
}
