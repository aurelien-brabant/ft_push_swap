/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psstack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:02:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 13:20:05 by abrabant         ###   ########.fr       */
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
** the t_psstack ADT.
*/

#ifndef PSHSWP_STACK_H
# define PSHSWP_STACK_H
# include <stddef.h>
# include <stdbool.h>

/*
** A top value of zero means that the stack is empty. Top element of the stack
** can be accessed using data[top - 1] if top != 0.
*/

typedef struct s_psstack
{
	size_t		size;
	size_t		capacity;
	size_t		top;
	int			*data;
}	t_psstack;

t_psstack		*stack_new(void);

/*
** Push a new number on the top of the stack.
*/

void			stack_push(t_psstack *stack, int nb);

/*
** Pop, i.e remove the element on the top of the stack and return it.
*/

int				stack_pop(t_psstack *stack);

/*
** Get the value of the top element of the stack
*/

int				stack_peek(t_psstack *stack);

int				stack_lookup(t_psstack *stack, size_t index);

size_t			stack_size(t_psstack *stack);

bool			stack_issorted(t_psstack *stack);

bool			stack_isempty(t_psstack *stack);

/*
** Check if stack contains duplicate elements. As elements are obviously not
** sorted, a simple linear search is used to determine if duplicates are present.
** Time complexity of such an algorithm is O(n^2), which is definitely slow.
*/

int				stack_search(t_psstack *stack, int nb);

void			stack_rotate_up(t_psstack *stack);

void			stack_rotate_down(t_psstack *stack);

void			stack_destroy(t_psstack *stack);

#endif
