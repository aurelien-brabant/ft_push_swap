/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:02:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/17 09:34:09 by abrabant         ###   ########.fr       */
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
** the t_stack ADT.
*/

#ifndef STACK_H
# define STACK_H
# include <stddef.h>
# include <stdbool.h>
# include "pushswap/pstypes.h"

/*
** A top value of zero means that the stack is empty. Top element of the stack
** can be accessed using data[top - 1] if top != 0.
*/

t_stack		*stack_new(void);

/*
** Push a new number on the top of the stack.
*/

void			stack_push(t_stack *stack, int nb);

void			stack_push_from_to(t_stack *from, t_stack *to);

int				stack_peek(t_stack *stack);

int				stack_lookup(t_stack *stack, size_t index);

size_t			stack_size(t_stack *stack);

bool			stack_issorted(t_stack *stack);

bool			stack_isempty(t_stack *stack);

int				stack_search(t_stack *stack, int nb);

void			stack_rotate_up(t_stack *stack);

void			stack_rotate_down(t_stack *stack);

void			stack_swap_top(t_stack *stack);

void			stack_destroy(t_stack *stack);

void			stack_get_max(t_stack *stack, int *hold_max, int *hold_max_index);

void			stack_get_min(t_stack *stack, int *hold_min, int *hold_min_index);

int				*stack_to_array(t_stack *stack);

#endif
