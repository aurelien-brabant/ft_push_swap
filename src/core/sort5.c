#include "pushswap/pscore.h"
#include "pushswap/cmd.h"
#include "pushswap/stack.h"

void	sort5(t_pushswap *ps)
{
	int	peek_b;

	outcmd(ps, PS_PUSH_B);
	peek_b = stack_peek(ps->stack_b);
	sort4(ps);
	if (peek_b < stack_peek(ps->stack_a))
		outcmd(ps, PS_PUSH_A);
	else if (peek_b > gsv(ps->stack_a, 3))
	{
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_ROT_A);
	}
	else if (peek_b > stack_peek(ps->stack_a) && peek_b < gsv(ps->stack_a, 1))
	{
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_SWAP_A);
	}
	else if (peek_b > gsv(ps->stack_a, 2) && peek_b < gsv(ps->stack_a, 3))
	{
		outcmd(ps, PS_REV_ROT_A);
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_ROT_A);
		outcmd(ps, PS_ROT_A);
	}
	else if (peek_b > gsv(ps->stack_a, 1) && peek_b < gsv(ps->stack_a, 2))
	{
		outcmd(ps, PS_ROT_A);
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_SWAP_A);
		outcmd(ps, PS_REV_ROT_A);
	}
}
