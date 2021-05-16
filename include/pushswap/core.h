/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:54:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/05/16 12:39:28 by abrabant         ###   ########.fr       */
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

void	exit_program(t_gc gc, int exit_code);

/*
** Add cmd to the cmdset (which is to printed at the end of the program) and
** execute the given instruction on the stacks.
*/

void	outcmd(t_pushswap *ps, const char *cmd);

/*
** Entrypoint function, responsible for generating the required list of
** push_swap instructions.
*/

void	generate(t_pushswap *ps);

/*
** Dumb shortcut to access element at a specific index in a stack
*/

int		gsv(t_stack *a, size_t index);

/*
** Sorting functions
*/

//void	bsort(t_cmd *cmdlist, t_stacks *stacks, t_array set);
void	sort3(t_pushswap *ps);
void	chunk_sort(t_pushswap *ps);

#endif
