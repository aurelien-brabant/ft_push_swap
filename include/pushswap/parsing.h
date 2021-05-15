/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:33:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 12:46:23 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "libft/gc.h"

# include "pushswap/stack.h"

/*
** Parse the command line arguments, filling the stack A with all the
** passed numbers. If no error occurs, the stack is returned. Otherwise,
** the execution of the program will be stopped, and the content of gc
** will be freed.
*/

t_stack	*parse_cli(int ac, char **av, t_gc gc);

#endif
