/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:55:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 04:28:50 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

int	stack_peek(t_psstack *stack)
{
	if (stack->top != NULL)
		return (stack->top->val);
	return (0);
}
