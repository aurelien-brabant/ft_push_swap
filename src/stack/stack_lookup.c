/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lookup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:09:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 12:08:40 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psstack.h"

int	stack_lookup(t_psstack *stack, size_t index)
{
	return (stack->data[index]);
}
