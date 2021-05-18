/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscore.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:54:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/18 17:36:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSCORE_H
# define PSCORE_H
# include "libft/gc.h"
# include "libft/array.h"
# include "pushswap/pstypes.h"
# define CHUNK_NB 5

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

//void	bsort(t_cmd *cmdlist, t_stacks *stacks, t_array set);
void		sort3(t_pushswap *ps);
void		chunk_sort(t_pushswap *ps);
void		sort100(t_pushswap *ps);
void		sort500(t_pushswap *ps);
void		get_bounds(t_pushswap *ps, t_bounds *bounds, size_t div_by);

/* sort utils */
void		insert(t_pushswap *ps, t_bounds bounds);
void		insert_all(t_pushswap *ps, t_bounds bounds);
void		move_item_to_top(t_pushswap *ps, int item_index, t_bounds bounds);
const char	*optimize(t_pushswap *ps, const char *cmd, t_bounds bounds,
				int item_index);
void		split(t_pushswap *ps, t_bounds bounds);
bool		is_oob(int v, t_bounds bounds);
int			select_value_by_index(t_stack *stack);

#endif
