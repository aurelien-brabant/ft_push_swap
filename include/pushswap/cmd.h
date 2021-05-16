/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:04:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:38:16 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include "pushswap/pstypes.h"

/* push_swap operations constants */

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

# define CMD_NB 11

t_cmd	*cmd_getlist(void);

/*
** Execute a push swap directive dealing with the stacks a and b.
** Valid push swap directives are described in the subject, page 7.
*/

bool	cmd_exec(t_pushswap *ps, const char *cmd);

/*
** push_swap commands implementation: these are not meant to be called directly
** as cmd_exec is the preferred way to execute commands. The only reason the
** prototypes below are visible is to comply with norm requirements (sadly).
*/

void	cmd_push_a(t_stack *a, t_stack *b);
void	cmd_push_b(t_stack *a, t_stack *b);
void	cmd_swap_a(t_stack *a, t_stack *b);
void	cmd_swap_b(t_stack *a, t_stack *b);
void	cmd_swap_double(t_stack *a, t_stack *b);
void	cmd_rotate_up_double(t_stack *a, t_stack *b);
void	cmd_rotate_down_double(t_stack *a, t_stack *b);
void	cmd_rotate_up_a(t_stack *a, t_stack *b);
void	cmd_rotate_up_b(t_stack *a, t_stack *b);
void	cmd_rotate_down_a(t_stack *a, t_stack *b);
void	cmd_rotate_down_b(t_stack *a, t_stack *b);

#endif
