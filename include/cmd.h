/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:04:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:35 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# include "pshswp_stack.h"
# define CMD_H
# define CMD_NB 11

typedef struct s_cmd
{
	char	*name;
	void	(*trigger)(t_pshswp_stack *a, t_pshswp_stack *b);
}				t_cmd;

t_cmd	*cmd_getlist(void);

/*
** Execute a push swap directive dealing with the stacks a and b.
** Valid push swap directives are described in the subject, page 7.
*/

bool	cmd_exec(t_cmd *cmdlist, const char *cmd, t_pshswp_stack *a,
				t_pshswp_stack *b);


void	cmd_push_a(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_push_b(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_swap_a(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_swap_b(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_swap_double(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_up_double(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_down_double(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_up_a(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_up_b(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_down_a(t_pshswp_stack *a, t_pshswp_stack *b);
void	cmd_rotate_down_b(t_pshswp_stack *a, t_pshswp_stack *b);

#endif
