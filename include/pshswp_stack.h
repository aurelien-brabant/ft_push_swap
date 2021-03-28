/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pshswp_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:02:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 03:13:24 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Implememtation of a simple FIFO data structure, to fit ft_push_swap's needs.
** This stack implementation automatically perform resizing if needed,
** because no stack limit is specifed by the subject.
**
** Do not confuse "stack" functions with "ft_stack" ones. The last are part
** of the libft, and are used to deal with "generic" stacks. To fit the needs
** of the project, this custom implementation is provided for the sake of
** efficiency and simplicity.
**
** NOTE: this is a stack implementation, not the direct implementation of
** the push_swap directives. They are implemented separately, and use
** the t_pshswp_stack ADT.
*/

#include <stddef.h>
#include <stdbool.h>

#ifndef PSHSWP_STACK_H
# define PSHSWP_STACK_H

/*
** A top value of zero means that the stack is empty. Top element of the stack
** can be accessed using data[top - 1] if top != 0.
*/

typedef struct s_pshswp_stack
{
	size_t		size;
	size_t		capacity;
	size_t		top;
	long long	*data;
}	t_pshswp_stack;



t_pshswp_stack	*stack_new(void);

/*
** Push a new number on the top of the stack.
*/

void			stack_push(t_pshswp_stack *stack, long long nb);

/*
** Pop, i.e remove the element on the top of the stack and return it.
*/

long long		stack_pop(t_pshswp_stack *stack);

/*
** Get the value of the top element of the stack
*/

long long		stack_peek(t_pshswp_stack *stack);

bool			stack_isempty(t_pshswp_stack *stack);

void			stack_rotate_up(t_pshswp_stack *stack);

void			stack_rotate_down(t_pshswp_stack *stack);

#endif
