/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 11:02:27 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "ft_fprintf.h"
#include "libft.h"
#include <unistd.h>
#define WITH_FLAG 2
#define WITHOUT_FLAG 1

static void	print_echo(t_cmd *cmd, int i);

void	echo(t_cmd *cmd)
{
	if (cmd->argv[1] != NULL && ft_strncmp(cmd->argv[1], "-n",
			ft_strlen(cmd->argv[1]) + 1) == 0)
	{
		print_echo(cmd, WITH_FLAG);
	}
	else
	{
		print_echo(cmd, WITHOUT_FLAG);
		ft_fprintf(cmd->out_fd, "\n");
	}
}

static void	print_echo(t_cmd *cmd, int i)
{
	while (cmd->argv[i] != NULL)
	{
		ft_fprintf(cmd->out_fd, "%s", cmd->argv[i]);
		if (cmd->argv[i + 1] != NULL)
			ft_fprintf(cmd->out_fd, " ");
		i++;
	}
}
