/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_isempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:39:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 23:40:12 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "pshswp_stack.h"

bool	stack_isempty(t_pshswp_stack *stack)
{
	return (stack->size == 0);
}
