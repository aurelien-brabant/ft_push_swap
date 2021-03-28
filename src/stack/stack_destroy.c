/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:25:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 23:27:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pshswp_stack.h"

void	stack_destroy(t_pshswp_stack *stack)
{
	if (stack == NULL)
		return ;
	free(stack->data);
	free(stack);
}
