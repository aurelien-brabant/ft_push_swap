/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 01:28:23 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 05:43:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/array.h"
# include "libft/gc.h"
# include "psstack.h"

void	execute_instruction_set(t_array set, t_stacks *stacks, t_gc gc);

#endif
