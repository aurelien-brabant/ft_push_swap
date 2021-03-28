/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:26:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 03:13:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pshswp_stack.h"
#include "libft/string.h"

/*
** To perform some tests while developping
*/

int	main(void)
{
	t_pshswp_stack	*stack;

	stack = stack_new();
	for (long long i = 0; i < 25; ++i) {
		stack_push(stack, i);
	}
	stack_rotate_down(stack);
	while (!stack_isempty(stack)) {
		printf("%lld\n", stack_pop(stack));
	}
}
//e
