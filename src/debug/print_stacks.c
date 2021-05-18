/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:09:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 17:19:26 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"
#include "pushswap/pscore.h"
#include "libft/io.h"

void	print_stack(t_stack *stack)
{
	t_psnode	*cur;
	int			max;

	stack_get_max(stack, &max, NULL);
	cur = stack->top;
	while (cur != NULL)
	{
		if (cur->val == max)
			ft_printf("|     \033[1;31m%d\033[0m     |\n", cur->val);
		else
			ft_printf("|     %d     |\n", cur->val);
		cur = cur->prev;
	}
}
