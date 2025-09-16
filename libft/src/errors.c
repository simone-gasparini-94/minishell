/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:44:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/31 15:49:50 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "ft_fprintf.h"

void	check_argc(int argc, int n)
{
	if (argc != n)
	{
		ft_fprintf(STDERR_FILENO, "argc\n", n);
		exit (EXIT_FAILURE);
	}
}

void	check_syscall(int ret, char *msg)
{
	if (ret == -1)
	{
		perror(msg);
		exit (EXIT_FAILURE);
	}
}
