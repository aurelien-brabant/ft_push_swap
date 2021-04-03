/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:25:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 12:08:51 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "psstack.h"

void	stack_destroy(t_psstack *stack)
{
	if (stack == NULL)
		return ;
	free(stack->data);
	free(stack);
}
