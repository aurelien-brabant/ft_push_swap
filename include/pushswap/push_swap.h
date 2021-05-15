/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:26:17 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:40:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "libft/gc.h"
# include "libft/array.h"
# include "cmd.h"
# define PUSH_SWAP_H
# define PS_SWAP_A		"sa"
# define PS_SWAP_B		"sb"
# define PS_SWAP_AB		"ss"
# define PS_PUSH_A		"pa"
# define PS_PUSH_B		"pb"
# define PS_ROT_A 		"ra"
# define PS_ROT_B 		"rb"
# define PS_ROT_AB		"rr"
# define PS_REV_ROT_A	"rra"
# define PS_REV_ROT_B	"rrb"
# define PS_REV_ROT_AB	"rrr"

/*
** output the given push_swap cmd on stdout, followed by a newline character.
*/

void	outcmd(t_cmd *cmdlist, const char *cmd, t_stacks *stacks, t_array set);
void	generate(t_gc gc, t_stacks *stacks, t_array set);
int		gsv(t_stack *a, size_t index);

/*
** Sorting functions
**
** - cmdlist is the list of available commands: it is required to retrieve
**   and execute the correct command
** - stacks is a structure which holds the stack A and the stack B.
** - set is the list of commands, in order, processed so far.
**   This set is going to be printed at the end of the processing.
*/

void	bsort(t_cmd *cmdlist, t_stacks *stacks, t_array set);
void	sort3(t_cmd *cmdlist, t_stacks *stacks, t_array set);

#endif