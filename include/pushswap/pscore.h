/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscore.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:54:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/19 21:16:08 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSCORE_H
# define PSCORE_H
# include "libft/gc.h"
# include "libft/array.h"
# include "pushswap/pstypes.h"
# define SORT100_SPLIT_NB 3
# define SORT500_SPLIT_NB 7

/*
** Exit push_swap with exit_code, and wipe all the allocated
** ressources that have been put inside the garbage collector.
*/

void		exit_program(t_gc gc, int exit_code);

/*
** Add cmd to the cmdset (which is to printed at the end of the program) and
** execute the given instruction on the stacks.
*/

void		outcmd(t_pushswap *ps, const char *cmd);

/*
** Entrypoint function, responsible for generating the required list of
** push_swap instructions.
*/

void		generate(t_pushswap *ps);

/*
** Dumb shortcut to access element at a specific index in a stack
*/

int			gsv(t_stack *a, size_t index);

/*
** Sorting functions
*/

void		sort2(t_pushswap *ps);
void		sort3(t_pushswap *ps);
void		sort4(t_pushswap *ps);
void		sort5(t_pushswap *ps);
void		sort(t_pushswap *ps);
void		get_bounds(t_pushswap *ps, t_bounds *bounds, size_t div_by);

/* sort utils */
void		insert_all(t_pushswap *ps, t_bounds bounds);
void		move_item_to_top(t_pushswap *ps, int item_index, t_bounds bounds);

void		split(t_pushswap *ps, t_bounds bounds);
bool		is_oob(int v, t_bounds bounds);
int			select_value_by_index(t_stack *stack);

#endif
