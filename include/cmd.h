/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:04:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/28 14:17:04 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp_stack.h"

#ifndef CMD_H
# define CMD_H
# define CMD_NB 11

typedef struct	s_cmd
{
	char	*name;
	void	(*trigger)();
}				t_cmd;

t_cmd	*cmd_getlist(void);

/*
** Execute a push swap directive dealing with the stacks a and b.
** Valid push swap directives are described in the subject, page 7.
*/

void	cmd_exec(t_cmd *cmdlist, const char *cmd, t_pshswp_stack *a,
		t_pshswp_stack *b);

void	cmd_push_a(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_push_b(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_swap_a(t_pshswp_stack *a);
void	cmd_swap_b(t_pshswp_stack *a);
void	cmd_swap_double(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_up_double(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_down_double(t_pshswp_stack *a, t_pshswp_stack *b);

#endif
