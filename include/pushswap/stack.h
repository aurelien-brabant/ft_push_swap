/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psstack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:02:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/05 06:18:40 by abrabant         ###   ########.fr       */
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

/*
** A top value of zero means that the stack is empty. Top element of the stack
** can be accessed using data[top - 1] if top != 0.
*/

typedef struct s_psnode
{
	struct s_psnode		*prev;
	struct s_psnode		*next;
	int					val;
}	t_psnode;

typedef struct s_stack
{
	size_t			size;
	int				max; 
	int				min;
	struct s_psnode	*top;
	struct s_psnode	*bot;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

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

int			stack_get_min_index(t_stack *stack);

int			stack_get_max_index(t_stack *stack);

#endif
