/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:02:04 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/25 12:12:15 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_fprintf.h"
#include "built_in.h"
#include "cmds.h"
#include "clean.h"
#include "data.h"

static bool str_is_num(char *s);

void	ft_exit(t_data *data, t_cmd *cmd)
{
	uint8_t	status;

	if (cmd->argv[1] == NULL)
	{
		ft_fprintf(cmd->out_fd, "exit\n");
		if (cmd->data)
			free_data(data);
		exit (EXIT_SUCCESS);
	}
	else if (str_is_num(cmd->argv[1]) == false)
		ft_fprintf(STDERR_FILENO, "exit: argument is not a number\n");
	else if (cmd->argv[2] != NULL)
		ft_fprintf(STDERR_FILENO, "exit: too many arguments\n");
	else
	{
		ft_fprintf(cmd->out_fd, "exit\n");
		status = (uint8_t) ft_atoi(cmd->argv[1]);
		if (cmd->data)
			free_data(data);
		exit (status);
	}
}

static bool str_is_num(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
