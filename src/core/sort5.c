#include "pushswap/pscore.h"
#include "pushswap/cmd.h"
#include "pushswap/stack.h"

/*
** Main function has been divided to make this code norm compliant.
** This function handles the most complicated insertion scenarios, that
** both require 4 commands. If one of these two scenarios is selected, then
** the main function (sort5) will stop and not go further this call.
*/

static bool	handle_complicated_insertion(t_pushswap *ps, int peek_b)
{
	if (peek_b > gsv(ps->stack_a, 2) && peek_b < gsv(ps->stack_a, 3))
	{
		outcmd(ps, PS_REV_ROT_A);
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_ROT_A);
		outcmd(ps, PS_ROT_A);
		return (true);
	}
	if (peek_b > gsv(ps->stack_a, 1) && peek_b < gsv(ps->stack_a, 2))
	{
		outcmd(ps, PS_ROT_A);
		outcmd(ps, PS_PUSH_A);
		outcmd(ps, PS_SWAP_A);
		outcmd(ps, PS_REV_ROT_A);
		return (true);
	}
	return (false);
}

void	sort5(t_pushswap *ps)
{
	int	peek_b;

	outcmd(ps, PS_PUSH_B);
	peek_b = stack_peek(ps->stack_b);
	sort4(ps);
	if (handle_complicated_insertion(ps, peek_b))
		return ;
	outcmd(ps, PS_PUSH_A);
	if (peek_b > gsv(ps->stack_a, 4))
		outcmd(ps, PS_ROT_A);
	else if (peek_b > gsv(ps->stack_a, 1) && peek_b < gsv(ps->stack_a, 2))
		outcmd(ps, PS_SWAP_A);
}
