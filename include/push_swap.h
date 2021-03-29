/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:26:17 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/29 13:53:20 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "pshswp_stack.h"
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

void	outcmd(const char *cmd);
void	generate(t_pshswp_stack *a);

#endif
