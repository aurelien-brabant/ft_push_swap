/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:09:03 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 13:11:03 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"

void	cmd_push_a(t_pshswp_stack *a, t_pshswp_stack *b)
{
	stack_push(a, stack_pop(b));
}
