/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:15:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:20:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap/stack.h"

/*
** Get Stack Value
** Basically some shortcut to stack_lookup
*/

int	gsv(t_stack *a, size_t index)
{
	return (stack_lookup(a, index));
}
