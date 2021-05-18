#include "pushswap/pscore.h"
#include "pushswap/cmd.h"
#include "pushswap/stack.h"

void	sort2(t_pushswap *ps)
{
	if (stack_peek(ps->stack_a) > gsv(ps->stack_a, 1))
		outcmd(ps, PS_SWAP_A);
}
