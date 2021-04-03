/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:26:17 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "libft/gc.h"
# include "cmd.h"
# include "psstack.h"
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

void	outcmd(t_cmd *cmdlist, const char *cmd, t_psstack *a,
		t_psstack *b);
void	generate(t_gc gc, t_psstack *a);

/*
** Sorting algorithms
*/

void	bsort(t_cmd *cmdlist, t_psstack *a, t_psstack *b);

#endif
