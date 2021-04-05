/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_from_to.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:28:24 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 17:17:08 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "psstack.h"

void	stack_push_from_to(t_psstack *from, t_psstack *to)
{
	t_psnode	*tmp;

	if (from->size == 0)
		return ;
	--from->size;
	++to->size;
	tmp = from->top->prev;
	if (to->top == NULL)
	{
		to->top = from->top;
		to->bot = to->top;
	}
	else
	{
		to->top->next = from->top;
		from->top->prev = to->top;
		to->top = to->top->next;
	}
	from->top = tmp;
	from->top->next = NULL;
}
