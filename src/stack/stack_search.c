/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:09:27 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 04:41:48 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

int	stack_search(t_psstack *stack, int nb)
{
	t_psnode	*cur;
	size_t		i;

	i = 0;
	cur = stack->bot;
	while (cur != NULL)
	{
		if (cur->val == nb)
			return (i);
		cur = cur->next;
		++i;
	}
	return (-1);
}
