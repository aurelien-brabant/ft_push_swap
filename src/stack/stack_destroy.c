/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:25:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 04:25:35 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "psstack.h"

void	stack_destroy(t_psstack *stack)
{
	t_psnode	*cur;
	t_psnode	*tmp;

	if (stack == NULL)
		return ;
	cur = stack->bot;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(stack);
}
