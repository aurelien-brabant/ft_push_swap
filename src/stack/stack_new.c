/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:05:17 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 14:58:28 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "psstack.h"

t_psstack	*stack_new(void)
{
	t_psstack	*stack;

	stack = malloc(sizeof (*stack));
	stack->size = 0;
	stack->bot = NULL;
	stack->top = NULL;
	return (stack);
}
