/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:47:57 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 10:58:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft/io.h"
#include "libft/gc.h"

void	exit_program(t_gc gc, int exit_code)
{
	ft_gc_destroy(gc);
	if (exit_code != 0)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(exit_code);
}
